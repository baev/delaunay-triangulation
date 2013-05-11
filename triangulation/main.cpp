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

