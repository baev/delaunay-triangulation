//
//  edges_ds.cpp
//  triangulation
//
//  Created by Dmitry Baev on 15.05.13.
//  Copyright (c) 2013 Dmitry Baev. All rights reserved.
//

#include "edges_ds.h"
#include <time.h>
#include <stdlib.h>

edges_ds::edges_ds()
{
    srand(static_cast<int>(time(NULL)));
}

edges_ds::~edges_ds()
{
    edges_.clear();
}

size_t edges_ds::get_id(edge *e)
{
    size_t id;
    do
    {
        id = get_rand(UINT_MAX);
    } while (edges_.count(id));
    
    edges_[id] = e;
    edges_by_point_[e->get_vertex_id()] = e;
    return id;
}

edge * edges_ds::get_edge(size_t id) const
{
    return edges_.at(id);
}

edge * edges_ds::get_edge_by_point_id(size_t p_id) const
{
    return edges_by_point_.at(p_id);
}

size_t edges_ds::get_rand(size_t limit) const
{
    return rand() % limit;
}