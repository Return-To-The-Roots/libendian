// Copyright (c) 2005 - 2017 Settlers Freaks (sf-team at siedler25.org)
//
// This file is part of Return To The Roots.
//
// Return To The Roots is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// Return To The Roots is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Return To The Roots. If not, see <http://www.gnu.org/licenses/>.

#pragma once

#ifndef EndianIStreamAdapter_h__
#define EndianIStreamAdapter_h__

#include "EndianStreamAdapterBase.h"
#include <boost/type_traits/is_arithmetic.hpp>
#include <boost/utility/enable_if.hpp>
#include <vector>
 
namespace libendian{

    /// Adapter that reads from streams with a given endianess
    /// T_isBigEndian decides whether the stream endianess is big endian or little endian
    /// T_Stream: Adapted class (may be a reference type) which should support:
    ///     bool operator!, bool eof(), ignore(size_t): See base stream
    ///     T_Stream& read(char*, size_t) for reading
    ///     size_t tellg for getting the read position
    ///     seekg(long, dir = T_Stream::beg) && T_Stream::cur for seeking
    template<bool T_isBigEndian, class T_Stream>
    class EndianIStreamAdapter: public EndianStreamAdapterBase<T_isBigEndian, T_Stream>
    {
        typedef EndianStreamAdapterBase<T_isBigEndian, T_Stream> Base;
        typedef typename Base::Convert Convert;
    public:
        EndianIStreamAdapter();
        explicit EndianIStreamAdapter(T_Stream stream): Base(stream) {}
        template<typename T_InitType>
        explicit EndianIStreamAdapter(T_InitType& initArg): Base(initArg) {}
        template<typename T_InitType>
        explicit EndianIStreamAdapter(const T_InitType& initArg): Base(initArg) {}
        template<typename T_InitType, typename T_ArgType>
        explicit EndianIStreamAdapter(const T_InitType& initArg, const T_ArgType& arg): Base(initArg, arg) {}

        /// Read a value and return true on success, false on error
        template<typename T>
        bool read(T& value) { return read(&value, 1); }
        
        /// Read a buffer with the given number of elements
        template<typename T>
        bool read(T* buffer, size_t numValues)
        {
            if(!this->stream_.read(reinterpret_cast<char*>(buffer), numValues * sizeof(T)))
                return false;
            if(sizeof(T) == 1)
                return true;
            for(size_t i = 0; i < numValues; ++i, ++buffer)
                *buffer = Convert::toNative(*buffer);
            return true;
        }

        template<typename T>
        typename boost::enable_if< boost::is_arithmetic<T>, EndianIStreamAdapter >::type& operator>>(T& value)
        {
            read(value);
            return *this;
        }

        template<typename T, size_t numValues>
        EndianIStreamAdapter& operator>>(T (&value)[numValues])
        {
            read(value, numValues);
            return *this;
        }

        long getPosition()
        {
            return static_cast<long>(this->stream_.tellg());
        }

        void setPosition(long position)
        {
            this->stream_.seekg(position);
        }

        void setPositionRel(long position)
        {
            this->stream_.seekg(position, this->stream_.cur);
        }
    };

} // namespace libendian

  /// Overload for reading a vector of values
template<bool T_isBigEndian, class T_Stream, typename T>
libendian::EndianIStreamAdapter<T_isBigEndian, T_Stream>& operator>>(libendian::EndianIStreamAdapter<T_isBigEndian, T_Stream>& is,
    std::vector<T>& vec)
{
    if(vec.empty())
        return is;
    is.read(&vec[0], vec.size());
    return is;
}


#endif // EndianIStreamAdapter_h__
