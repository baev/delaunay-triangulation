//
//  main.cpp
//  triangulation
//
//  Created by Dmitry Baev on 16.05.13.
//  Copyright (c) 2013 Dmitry Baev. All rights reserved.
//

#include <iostream>
#include "lds.h"
#include "cg/io/point.h"
#include <gmpxx.h>
#include "points_ds.h"

int main()
{
    lds t;
    for (int i = 0; i < 100; i++)
    {
        size_t x = get_storage().get_rand(100);
        size_t y = get_storage().get_rand(100);
        t.add_vertex(mpoint(x, y));
    }
    
    std::cout << "you";
    return 0;
}