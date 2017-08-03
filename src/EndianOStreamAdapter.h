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

#ifndef EndianStreamAdapterO_h__
#define EndianStreamAdapterO_h__

#include "EndianStreamAdapterBase.h"
#include <boost/type_traits/is_arithmetic.hpp>
#include <boost/utility/enable_if.hpp>
#include <vector>
 
namespace libendian{

    /// Adapter that writes to streams with a given endianess
    /// T_isBigEndian decides whether the stream endianess is big endian or little endian
    /// T_Stream: Adapted class (may be a reference type) which should support:
    ///     bool operator!, bool eof(), ignore(size_t): See base stream
    ///     T_Stream& write(char*, size_t) for writing
    ///     size_t tellp for setting the write position
    ///     seekp(long, dir = T_Stream::beg) && T_Stream::cur for seeking
    template<bool T_isBigEndian, class T_Stream>
    class EndianOStreamAdapter: public EndianStreamAdapterBase<T_isBigEndian, T_Stream>
    {
        typedef EndianStreamAdapterBase<T_isBigEndian, T_Stream> Base;
        typedef typename Base::Convert Convert;
    public:
        EndianOStreamAdapter();
        explicit EndianOStreamAdapter(T_Stream stream): Base(stream){}
        template<typename T_InitType>
        explicit EndianOStreamAdapter(T_InitType& initArg): Base(initArg) {}
        template<typename T_InitType>
        explicit EndianOStreamAdapter(const T_InitType& initArg): Base(initArg) {}
        template<typename T_InitType, typename T_ArgType>
        explicit EndianOStreamAdapter(const T_InitType& initArg, const T_ArgType& arg): Base(initArg, arg) {}

         /// Write a value and return true on success, false on error
         template<typename T>
         bool write(const T& value) { return write(&value, 1); }

         /// Write a buffer with the given number of elements
         template<typename T>
         bool write(const T* buffer, size_t numValues)
         {
             // Optimization for single byte values -> no endianess change, just write it
             if(sizeof(T) == 1)
                 return writeRaw(buffer, numValues);

             for(size_t i = 0; i < numValues; ++i, ++buffer)
             {
                 const T tmp = Convert::fromNative(*buffer);
                 if(!writeRaw(&tmp, 1))
                     return false;
             }
             return true;
         }

         /// Write a buffer with the given number of elements without conversion
         template<typename T>
         bool writeRaw(const T* buffer, size_t numValues)
         {
             return !!this->stream_.write(reinterpret_cast<const char*>(buffer), numValues * sizeof(T));
         }
         
         template<typename T>
         typename boost::enable_if< boost::is_arithmetic<T>, EndianOStreamAdapter >::type& operator<<(const T& value)
         {
             write(value);
             return *this;
         }

         template<typename T, size_t numValues>
         EndianOStreamAdapter& operator<<(const T(&value)[numValues])
         {
             write(value, numValues);
             return *this;
         }

         long getPosition()
         {
             return static_cast<long>(this->stream_.tellp());
         }

         void setPosition(long position)
         {
             this->stream_.seekp(position);
         }

         void setPositionRel(long position)
         {
             this->stream_.seekp(position, this->stream_.cur);
         }
    };

    /// Overload for reading a vector of values
    template<bool T_isBigEndian, class T_Stream, typename T>
    EndianOStreamAdapter<T_isBigEndian, T_Stream>& operator<<(EndianOStreamAdapter<T_isBigEndian, T_Stream>& os, const std::vector<T>& vec)
    {
        if(vec.empty())
            return os;
        os.write(&vec[0], vec.size());
        return os;
    }


} // namespace libendian

#endif // EndianStreamAdapterO_h__
