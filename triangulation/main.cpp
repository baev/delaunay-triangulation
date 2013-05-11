//
//  main.cpp
//  triangulation
//
//  Created by Dmitry Baev on 09.05.13.
//  Copyright (c) 2013 Dmitry Baev. All rights reserved.
//

#include <iostream>
#include <gmp.h>
#include <gmpxx.h>
#include "tds.h"

int main(int argc, const char * argv[])
{
    tds t = tds();
    t.add_vertex(point(1, 2));
    
    return 0;
}

