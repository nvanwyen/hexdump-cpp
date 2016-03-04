//
// hexdump.hpp
// ~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2004-2012 Metasystems Technologies Inc. (MTI)
// All rights reserved
//
// Distributed under the MTI Software License, Version 0.1.
//
// as defined by accompanying file MTI-LICENSE-0.1.info or
// at http://www.mtihq.com/license/MTI-LICENSE-0.1.info
//

#ifndef __MTI_HEXDUMP_HPP
#define __MTI_HEXDUMP_HPP

// c

// c++
#include <string>
#include <vector>
#include <istream>
#include <fstream>
#include <iostream>

// boost

// local

//
namespace mti { 

//
class hexdump
{
    public:
        // modified from: http://www.i42.co.uk/stuff/hexdump.htm
        template<class elem, class traits>
        inline static void out( const void* data, 
                                std::size_t size, 
                                std::basic_ostream<elem, traits>& stream, 
                                std::size_t width = 16 )
        {
            const char* const start = static_cast<const char*>(data);
            const char* const end = start + size;
            const char* line = start;

            stream << std::endl << std::endl;

            stream << "index  data             dump [size: " << std::dec << size << "]" << std::endl;
            stream << "-----  ---------------- -----------------------------------------------" << std::endl;

            while ( line != end )
            {
                stream.width( 4 );
                stream.fill( '0' );
                stream << std::hex << line - start << " : ";
                std::size_t length = std::min( width, static_cast<std::size_t>( end - line ) );

                for ( std::size_t pass = 1; pass <= 2; ++pass )
                {   
                    for ( const char* next = line; next != end && next != line + width; ++next )
                    {
                        char ch = *next;

                        switch ( pass )
                        {
                            case 1:
                                stream << ( ch < 32 ? '.' : ch );
                                break;

                            case 2:
                                if ( next != line )
                                    stream << " ";

                                stream.width( 2 );
                                stream.fill( '0' );
                                stream << std::hex << std::uppercase << static_cast<int>( static_cast<unsigned char>( ch ) );
                                break;
                        }
                    }

                    if ( pass == 1 && length != width )
                        stream << std::string( width - length, ' ' );

                    stream << " ";
                }

                stream << std::endl;
                line = line + length;
            }

            stream << std::endl;
        }
};

} // namespace mti

#endif // __MTI_HEXDUMP_HPP

