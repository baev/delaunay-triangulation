//
//  edges_ds.h
//  triangulation
//
//  Created by Dmitry Baev on 15.05.13.
//  Copyright (c) 2013 Dmitry Baev. All rights reserved.
//

#ifndef __triangulation__edges_ds__
#define __triangulation__edges_ds__

#include <iostream>
#include <map>
#include "edge.h"

struct edges_ds
{
    edges_ds();
    ~edges_ds();
    
    size_t get_id(edge *e);
    edge * get_edge(size_t id) const;
    edge * get_edge_by_point_id(size_t p_id) const;
    
    size_t get_rand(size_t limit) const;
    
private:
    std::map<size_t, edge *> edges_;
    std::map<size_t, edge *> edges_by_point_;
};

#endif /* defined(__triangulation__edges_ds__) */
