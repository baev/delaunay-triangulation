//
//  points_ds.h
//  triangulation
//
//  Created by Dmitry Baev on 11.05.13.
//  Copyright (c) 2013 Dmitry Baev. All rights reserved.
//

#ifndef __triangulation__points_ds__
#define __triangulation__points_ds__

#include <iostream>
#include <map>
#include "edge.h"
#include <limits>

struct points_ds
{
    points_ds();
    ~points_ds();
    
    size_t get_id(mpoint *p);
    mpoint * get_point(size_t id) const;
    
    size_t get_rand(size_t limit) const;
    size_t get_inf_point_id() const;
    
private:
    size_t inf_point_id_;
    std::map<size_t, mpoint *> points_;
};

points_ds& get_storage();

#endif /* defined(__triangulation__points_ds__) */
