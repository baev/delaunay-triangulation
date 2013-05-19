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
#include <ctime>
#include <boost/random.hpp>

template<class T>
struct distribution
{ // general case, assuming T is of integral type
    typedef boost::uniform_int<> type;
};

template<>
struct distribution<float>
{ // float case
    typedef boost::uniform_real<> type;
};

template<>
struct distribution<double>
{ // double case
    typedef boost::uniform_real<> type;
};

template <typename N> N getRandom(N min, N max)
{
    typedef typename distribution<N>::type distro_type;
    

    boost::mt19937 seed( static_cast<int>(rand()));
    distro_type dist(min,max);
    boost::variate_generator<boost::mt19937&, distro_type > random(seed,dist);
    return random();
};

int main()
{
    
    srand(static_cast<int>(time(NULL)));
    long tt = time(NULL);
    lds t;
    for (int i = 0; i < 10000; i++)
    {
        double x = getRandom<double>(-10000, 10000);
        double y = getRandom<double>(-10000, 10000);
//        std::cout << x << " " << y << std::endl;
//        double x = reinterpret_cast<double>(random());
//        double y = reinterpret_cast<double>(random());
//        size_t x = get_storage().get_rand(10000);
//        size_t y = get_storage().get_rand(10000);
        t.add_vertex(mpoint(x, y));
    }
    long tt2 = time(NULL);
    std::cout << tt2 - tt << std::endl;
    
    std::cout << "you";
    return 0;
}