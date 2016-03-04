//
// main.cpp
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

#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>

#include "hexdump.hpp"

int main( int argc, char** argv )
{

    if ( argc != 2 )
    {
        std::cout << "Usage: " << argv[0] << " <file_name>" << std::endl;
        return 1;
    }

    std::ifstream file( argv[1] );
    std::istream_iterator<char> begin( file ), end;
    std::vector<char> data( begin, end );

    mti::hexdump::out( &data[0], data.size(), std::cout );

    return 0;
}
