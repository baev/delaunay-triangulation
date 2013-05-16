//
//  points_ds.cpp
//  triangulation
//
//  Created by Dmitry Baev on 11.05.13.
//  Copyright (c) 2013 Dmitry Baev. All rights reserved.
//

#include "points_ds.h"
#include <time.h>

mpoint * get_inf_point();

points_ds::points_ds()
{
    srand(static_cast<int>(time(NULL)));
    inf_point_id_ = get_id(get_inf_point());
}

points_ds::~points_ds()
{
    points_.clear();
}

size_t points_ds::get_rand(size_t limit) const
{
    return rand() % limit;
}

size_t points_ds::get_id(mpoint *p)
{
    size_t id;
    do
    {
        id = get_rand(UINT_MAX);
    } while (points_.count(id));
    
    points_[id] = p;
    return id;
}

size_t points_ds::get_inf_point_id() const
{
    return inf_point_id_;
}

mpoint * points_ds::get_point(size_t id) const
{
    return points_.at(id);
}

points_ds& get_storage()
{
    static points_ds storage;
    return storage;
}