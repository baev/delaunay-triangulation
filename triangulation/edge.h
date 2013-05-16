//
//  edge.h
//  triangulation
//
//  Created by Dmitry Baev on 09.05.13.
//  Copyright (c) 2013 Dmitry Baev. All rights reserved.
//

#ifndef __triangulation__edge__
#define __triangulation__edge__

#include <iostream>
#include "mpoint.h"
#include "triangle.h"

struct edge
{
    edge(size_t vertex_id, edge *next, edge* twin);
    
    void set_next(edge * next);
    void set_twin(edge * twin);
    
    edge * next() const;
    edge * twin() const;
    
    size_t get_vertex_id() const;
    
    mpoint v1() const;
    mpoint v2() const;
    
    void set_my_id(size_t id);
    size_t get_my_id() const;
    
//    triangle * get_triangle() const;
    
    edge * get_edge(size_t id);
    
private:
    size_t my_id_;
    
    size_t vertex_id_;
    edge * next_;
    edge * twin_;
};



#endif /* defined(__triangulation__edge__) */
