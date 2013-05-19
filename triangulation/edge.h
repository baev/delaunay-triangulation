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
<<<<<<< HEAD
#include "mpoint.h"
=======
#include "point.h"
>>>>>>> b0edb06856069410d4e3f1a3964c05bffadb8848
#include "triangle.h"

struct edge
{
<<<<<<< HEAD
    edge(size_t vertex_id, edge *next, edge* twin);
    
    void set_next(edge * next);
    void set_twin(edge * twin);
=======
    edge(size_t vertex_id, size_t next_id, size_t twin_id);
    
    void set_next(size_t next_id);
    void set_twin(size_t twin_id);
>>>>>>> b0edb06856069410d4e3f1a3964c05bffadb8848
    
    edge * next() const;
    edge * twin() const;
    
    size_t get_vertex_id() const;
    
<<<<<<< HEAD
    mpoint v1() const;
    mpoint v2() const;
    
    void set_my_id(size_t id);
    size_t get_my_id() const;
    
//    triangle * get_triangle() const;
=======
    triangle * get_triangle() const;
>>>>>>> b0edb06856069410d4e3f1a3964c05bffadb8848
    
    edge * get_edge(size_t id);
    
private:
<<<<<<< HEAD
    size_t my_id_;
    
    size_t vertex_id_;
    edge * next_;
    edge * twin_;
};


=======
    size_t vertex_id_;
    size_t next_id_;
    size_t twin_id_;
};

size_t create_edge(size_t vertex_id, size_t next_id, size_t twin_id);
size_t get_vertex_id(size_t edge_id);
void set_next_by_id(size_t edge_id, size_t next_id);
void set_twin_by_id(size_t edge_id, size_t twin_id);
point get_vertex(size_t edge_id);
>>>>>>> b0edb06856069410d4e3f1a3964c05bffadb8848

#endif /* defined(__triangulation__edge__) */
