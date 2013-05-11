//
//  edge.cpp
//  triangulation
//
//  Created by Dmitry Baev on 09.05.13.
//  Copyright (c) 2013 Dmitry Baev. All rights reserved.
//

#include "edge.h"
#include "data_struct.h"

edge::edge(size_t v_id, size_t n_id, size_t t_id)
: vertex_id_(v_id), next_id_(n_id), twin_id_(t_id)
{
}

void edge::set_next(size_t next_id)
{
    next_id_ = next_id;
}

void edge::set_twin(size_t twin_id)
{
    twin_id_ = twin_id;
}

edge * edge::next() const
{
    return get_storage().get_edge(next_id_);
}

edge * edge::twin() const
{
    return get_storage().get_edge(twin_id_);
}

size_t edge::get_vertex_id() const
{
    return vertex_id_;
}

triangle * edge::get_triangle() const
{
    size_t a = get_vertex_id();
    size_t b = next()->get_vertex_id();
    size_t c = next()->next()->get_vertex_id();
    
    return new triangle(a, b, c);
}

size_t create_edge(size_t vertex_id, size_t next_id, size_t twin_id)
{
    return get_storage().get_id(new edge(vertex_id, next_id, twin_id));
}

size_t get_vertex_id(size_t edge_id)
{
    return get_storage().get_edge(edge_id)->get_vertex_id();
}

void set_next_by_id(size_t edge_id, size_t next_id)
{
    get_storage().get_edge(edge_id)->set_next(next_id);
}

void set_twin_by_id(size_t edge_id, size_t twin_id)
{
    get_storage().get_edge(edge_id)->set_twin(twin_id);
}

point get_vertex(size_t edge_id)
{
    size_t v_id = get_storage().get_edge(edge_id)->get_vertex_id();
    return *get_storage().get_point(v_id);
}
