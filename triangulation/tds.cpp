//
//  tds.cpp
//  triangulation
//
//  Created by Dmitry Baev on 09.05.13.
//  Copyright (c) 2013 Dmitry Baev. All rights reserved.
//

#include "tds.h"
#include "point.h"
#include <list>
#include "data_struct.h"


tds::tds() {
    tds_.push_back(new triangulation());
}

//tds::~tds() {
//    for (int i = 0; i < tds_.size(); i++)
//    {
//        delete tds_[i];
//    }
//}

bool tds::contains(const point p) const
{
    size_t nearest_id = tds_[tds_.size() - 1]->locate(p);
    
    for(size_t i = tds_.size() - 1; i != 0 && get_vertex(nearest_id) != p; i--)
    {
        nearest_id = tds_[i]->locate(p, nearest_id);
    }
    
    return get_vertex(nearest_id) == p;
}

std::list<size_t> tds::locate(const point p) const
{
    std::list<size_t> result;
    
    size_t nearest_id = tds_[tds_.size() - 1]->locate(p);
    result.push_front(nearest_id);
    
    for(size_t i = tds_.size() - 1; i != 0; i--)
    {
        nearest_id = tds_[i]->locate(p, nearest_id);
        result.push_front(nearest_id);
    }
    
    return result;
}

void tds::add_vertex(const point p)
{
    size_t p_id = get_storage().get_id(new point(p));
    
    std::list<size_t> nearest = locate(p);
    int index = 0;
    do
    {
        if (tds_.size() <= index)
        {
            tds_.push_back(new triangulation());
        }
        
        tds_[index++]->add_vertex(p_id, nearest.front());
        if (nearest.size())
        {
            nearest.pop_front();
        }
        
    } while (get_storage().get_rand(100) < MAGIC_CONST);
}