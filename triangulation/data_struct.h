//
//  data_struct.h
//  triangulation
//
//  Created by Dmitry Baev on 11.05.13.
//  Copyright (c) 2013 Dmitry Baev. All rights reserved.
//

#ifndef __triangulation__data_struct__
#define __triangulation__data_struct__

#include <iostream>
#include <map>
#include "edge.h"
#include <limits>

struct data_struct
{
    data_struct();
    
    size_t get_id(point *p);
    size_t get_id(edge *e);
    
    point * get_point(size_t id) const;
    edge * get_edge(size_t id) const;
    
    size_t get_rand(size_t limit) const;
    size_t get_inf_point_id() const;
    
private:
    size_t inf_point_id_;
    std::map<size_t, point *> points_;
    std::map<size_t, edge *> edges_;
};

data_struct& get_storage()
{
    static data_struct storage;
    return storage;
}

#endif /* defined(__triangulation__data_struct__) */
