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
#include "point.h"
#include "triangle.h"

struct edge
{
    edge(size_t vertex_id, size_t next_id, size_t twin_id);
    
    void set_next(size_t next_id);
    void set_twin(size_t twin_id);
    
    edge * next() const;
    edge * twin() const;
    
    size_t get_vertex_id() const;
    
    triangle * get_triangle() const;
    
    edge * get_edge(size_t id);
    
private:
    size_t vertex_id_;
    size_t next_id_;
    size_t twin_id_;
};

size_t create_edge(size_t vertex_id, size_t next_id, size_t twin_id);
size_t get_vertex_id(size_t edge_id);
void set_next_by_id(size_t edge_id, size_t next_id);
void set_twin_by_id(size_t edge_id, size_t twin_id);
point get_vertex(size_t edge_id);

#endif /* defined(__triangulation__edge__) */
