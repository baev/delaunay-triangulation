//
//  main.cpp
//  triangulation
//
<<<<<<< HEAD
//  Created by Dmitry Baev on 16.05.13.
=======
//  Created by Dmitry Baev on 09.05.13.
>>>>>>> b0edb06856069410d4e3f1a3964c05bffadb8848
//  Copyright (c) 2013 Dmitry Baev. All rights reserved.
//

#include <iostream>
<<<<<<< HEAD
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
=======
#include <gmp.h>
#include <gmpxx.h>
#include "tds.h"
#include "data_struct.h"

int main(int argc, const char * argv[])
{
    tds t = tds();
    
    for (int i = 0; i < 100; i++)
    {
        size_t x = get_storage().get_rand(100);
        size_t y = get_storage().get_rand(100);
        t.add_vertex(point(x, y));
    }
    std::cout << "you";
    
//    size_t t = get_storage().get_id(new point(1, 13));
//    point *p = get_storage().get_point(t);
//    
//    std::cout << p->get_x_coord() << " " << p-> get_y_coord() << std::endl;
//    
//    size_t tt = create_edge(t, NULL, NULL);
//    edge *e = get_storage().get_edge(tt);
//    
//    std::cout << e->get_vertex_id() << " " << t << std::endl;
//    
//    set_twin_by_id(tt, tt);
//   
//    size_t i = get_storage().get_inf_point_id();
//    p = get_storage().get_point(i);
//    
//    std::cout << i << std::endl;
//    std::cout << p->get_x_coord()
//        << " " << p->get_y_coord()
//        << " " << p->get_z_coord() << std::endl;
    
    return 0;
}

>>>>>>> b0edb06856069410d4e3f1a3964c05bffadb8848
