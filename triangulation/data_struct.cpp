//
//  data_struct.cpp
//  triangulation
//
//  Created by Dmitry Baev on 11.05.13.
//  Copyright (c) 2013 Dmitry Baev. All rights reserved.
//

#include "data_struct.h"
#include <time.h>

point * get_inf_point();

data_struct::data_struct()
{
    srand(static_cast<int>(time(NULL)));
    inf_point_id_ = get_id(get_inf_point());
}

size_t data_struct::get_rand(size_t limit) const
{
    return rand() % limit;
}

size_t data_struct::get_id(point *p)
{
    size_t id;
    do
    {
        id = get_rand(UINT_MAX);
    } while (points_.count(id));
    
    points_[id] = p;
    return id;
}

size_t data_struct::get_id(edge *e)
{
    size_t id;
    do
    {
        id = get_rand(UINT_MAX);
    } while (edges_.count(id));
    
    edges_[id] = e;
    return id;
}

size_t data_struct::get_inf_point_id() const
{
    return inf_point_id_;
}

point * data_struct::get_point(size_t id) const
{
    return points_.at(id);
}

edge * data_struct::get_edge(size_t id) const
{
    return edges_.at(id);
}