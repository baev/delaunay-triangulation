//
//  lds.cpp
//  triangulation
//
//  Created by Dmitry Baev on 09.05.13.
//  Copyright (c) 2013 Dmitry Baev. All rights reserved.
//

#include "lds.h"
#include "mpoint.h"
#include <list>
#include "points_ds.h"


lds::lds() {
    lds_.push_back(new tds());
}


//bool lds::contains(const point p) const
//{
//    size_t nearest_id = lds_[lds_.size() - 1]->locate(p);
//    
//    for(size_t i = lds_.size() - 1; i != 0 && get_vertex(nearest_id) != p; i--)
//    {
//        nearest_id = lds_[i]->locate(p, nearest_id);
//    }
//    
//    return get_vertex(nearest_id) == p;
//}

std::list<edge *> lds::locate(const mpoint p) const
{
    std::list<edge *> result;
    
    edge *nearest = lds_[lds_.size() - 1]->locate(p);
    result.push_front(nearest);
    
    for(int i = static_cast<int>(lds_.size()) - 2; i >= 0; i--)
    {
        nearest = lds_[i]->locate(p, nearest->get_vertex_id());
        result.push_front(nearest);
    }
    
    return result;
}

void lds::add_vertex(const mpoint p)
{
    size_t p_id = get_storage().get_id(new mpoint(p));
    
    std::list<edge *> nearest = locate(p);
    mpoint p_tmp = *get_storage().get_point(nearest.front()->get_vertex_id());
    
    if (p_tmp == p)
    {
        return;
    }
    
    int index = 0;
    do
    {
        if (lds_.size() <= index || !nearest.size())
        {
            lds_.push_back(new tds());
            edge *n = lds_[index]->locate(p);
            lds_[index++]->add_vertex(p_id, n);
        }
        else
        {
            lds_[index++]->add_vertex(p_id, nearest.front());
            nearest.pop_front();
        }
        
    } while (get_storage().get_rand(100) < MAGIC_CONST);
}

std::vector<edge> lds::get_edges()
{
    return lds_[0]->edges();
}