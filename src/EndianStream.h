// Copyright (c) 2005 - 2015 Settlers Freaks (sf-team at siedler25.org)
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

#include "ConvertEndianess.h"
#include "FileError.h"
#include <iosfwd>
#include <vector>

namespace libendian{

    template<bool T_isBigEndian, class T_Stream = std::ifstream>
    class EndianBaseStream
    {
    protected:
        T_Stream stream_;
        typedef ConvertEndianess<T_isBigEndian> Convert;

    public:
        explicit EndianBaseStream(const std::string& filePath): stream_(filePath, std::ios_base::binary)
        {
            stream_.imbue(std::locale::classic());
        }

        EndianBaseStream(T_Stream stream): stream_(stream)
        {}

        T_Stream& getStream()
        {
            return stream_;
        }

        bool operator!() const
        {
            return !stream_;
        }

        bool isEOF()
        {
            return stream_.eof();
        }

        EndianBaseStream& ignore(size_t size)
        {
            stream_.ignore(size);
            return *this;
        }
    };

    /**
     * Filestream adapter that reads from streams with a given endianess
     */
    template<bool T_isBigEndian, class T_Stream = std::ifstream>
    class EndianIStream: public EndianBaseStream<T_isBigEndian, T_Stream>
    {
        typedef EndianBaseStream<T_isBigEndian, T_Stream> Base;
    public:
        explicit EndianIStream(const std::string& filePath): Base(filePath)
        {}

        EndianIStream(T_Stream stream): Base(stream)
        {}

        /**
         * Reads a value or vector of values and throws an exception on failure
         */
        template<typename T>
        void read(T& value)
        {
            if(!readNoExcept(value))
                onError();
        }

        /**
         * Reads a buffer with the given size (no conversion done)
         */
        void read(unsigned char* buffer, size_t size)
        {
            if(!readNoExcept(buffer, size))
                onError();
        }

        /**
         * Reads a buffer with the given size (no conversion done)
         */
        void read(char* buffer, size_t size)
        {
            if(!readNoExcept(buffer, size))
                onError();
        }

        /**
         * Reads a value and returns true on success, false on error
         */
        template<typename T>
        bool readNoExcept(T& value)
        {
            if(!stream_.read(reinterpret_cast<char*>(&value), sizeof(T)))
                return false;
            value = Convert::toNative(value);
            return true;
        }

        /**
         * Reads a vector of values and returns true on success, false on error
         */
        template<typename T>
        bool readNoExcept(std::vector<T>& vec)
        {
            for(std::vector<T>::iterator it = vec.begin(); it != vec.end(); ++it)
            {
                if(!readNoExcept(*it))
                    return false;
            }
            return true;
        }

        /**
         * Reads a buffer with the given size (no conversion done)
         */
        bool readNoExcept(unsigned char* buffer, size_t size)
        {
            return readNoExcept(reinterpret_cast<char*>(buffer), size);
        }

        /**
         * Reads a buffer with the given size (no conversion done)
         */
        bool readNoExcept(char* buffer, size_t size)
        {
            return !!stream_.read(buffer, size);
        }

        template<typename T>
        EndianIStream& operator>>(T& value)
        {
            read(value);
            return *this;
        }

        template<size_t size>
        EndianIStream& operator>>(char (&value)[size])
        {
            read(value, size);
            return *this;
        }

        template<size_t size>
        EndianIStream& operator>>(unsigned char (&value)[size])
        {
            read(value, size);
            return *this;
        }

        long getPosition()
        {
            return static_cast<long>(stream_.tellg());
        }

        void setPosition(long position)
        {
            stream_.seekg(position);
        }

        void setPositionRel(long position)
        {
            stream_.seekg(position, stream_.cur);
        }

    protected:
        void onError(const std::string& msg = "Error reading from file")
        {
            throw FileError(msg);
        }
    };

    /**
     * Filestream adapter that writes to streams with a given endianess
     */
    template<bool T_isBigEndian, class T_Stream = std::ofstream>
    class EndianOStream: public EndianBaseStream<T_isBigEndian, T_Stream>
    {
        typedef EndianBaseStream<T_isBigEndian, T_Stream> Base;
    public:
        explicit EndianOStream(const std::string& filePath): Base(filePath)
        {}

        EndianOStream(T_Stream stream): Base(stream)
        {}

        /**
         * Writes a value or vector of values and throws an exception on failure
         */
        template<typename T>
        void write(const T& value)
        {
            if(!writeNoExcept(value))
                onError();
        }

        /**
         * Writes a buffer with the given size (no conversion done)
         */
        void write(const unsigned char* buffer, size_t size)
        {
            if(!writeNoExcept(buffer, size))
                onError();
        }

        /**
         * Writes a buffer with the given size (no conversion done)
         */
        void write(const char* buffer, size_t size)
        {
            if(!writeNoExcept(buffer, size))
                onError();
        }

        /**
         * Writes a value and returns true on success, false on error
         */
        template<typename T>
        bool writeNoExcept(const T& value)
        {
            const T valueFile = Convert::fromNative(value);
            if(!stream_.write(reinterpret_cast<const char*>(&valueFile), sizeof(T)))
                return false;
            return true;
        }

        /**
         * Writes a vector of values and returns true on success, false on error
         */
        template<typename T>
        bool writeNoExcept(const std::vector<T>& vec)
        {
            for(std::vector<T>::const_iterator it = vec.begin(); it != vec.end(); ++it)
            {
                if(!writeNoExcept(*it))
                    return false;
            }
            return true;
        }

        /**
         * Writes a buffer with the given size (no conversion done)
         */
        bool writeNoExcept(const unsigned char* buffer, size_t size)
        {
            return writeNoExcept(reinterpret_cast<const char*>(buffer), size);
        }

        /**
         * Writes a buffer with the given size (no conversion done)
         */
        bool writeNoExcept(const char* buffer, size_t size)
        {
            return !!stream_.write(buffer, size);
        }

        template<typename T>
        EndianOStream& operator<<(const T& c)
        {
            write(c);
            return *this;
        }

        template<size_t size>
        EndianOStream& operator<<(char (&value)[size])
        {
            write(value, size);
            return *this;
        }

        template<size_t size>
        EndianOStream& operator<<(unsigned char (&value)[size])
        {
            write(value, size);
            return *this;
        }

        long getPosition()
        {
            return static_cast<long>(stream_.tellp());
        }

        void setPosition(long position)
        {
            stream_.seekp(position);
        }

        void setPositionRel(long position)
        {
            stream_.seekp(position, stream_.cur);
        }

    protected:
        void onError(const std::string& msg = "Error writing to file")
        {
            throw FileError(msg);
        }
    };

    typedef EndianIStream<false, std::ifstream> LittleEndianIFStream;
    typedef EndianIStream<false, std::istream&> LittleEndianIStreamRef;
    typedef EndianIStream<true, std::ifstream> BigEndianIFStream;
    typedef EndianIStream<true, std::istream&> BigEndianIStreamRef;

    typedef EndianOStream<false, std::ofstream> LittleEndianOFStream;
    typedef EndianOStream<false, std::ostream&> LittleEndianOStreamRef;
    typedef EndianOStream<true, std::ofstream> BigEndianOFStream;
    typedef EndianOStream<true, std::ostream&> BigEndianOStreamRef;


} // namspace libendian