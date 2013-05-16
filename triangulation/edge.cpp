//
//  edge.cpp
//  triangulation
//
//  Created by Dmitry Baev on 09.05.13.
//  Copyright (c) 2013 Dmitry Baev. All rights reserved.
//

#include "edge.h"
#include "points_ds.h"

edge::edge(size_t vertex_id, edge*next, edge*twin)
:vertex_id_(vertex_id), next_(next), twin_(twin)
{
}

void edge::set_next(edge *next)
{
    next_ = next;
}

void edge::set_twin(edge *twin)
{
    twin_ = twin;
}

void edge::set_my_id(size_t id)
{
    my_id_ = id;
}

edge * edge::next() const
{
    return next_;
}

edge * edge::twin() const
{
    return twin_;
}

size_t edge::get_vertex_id() const
{
    return vertex_id_;
}

mpoint edge::v1() const
{
    return *get_storage().get_point(get_vertex_id());
}

mpoint edge::v2() const
{
    return *get_storage().get_point(next()->get_vertex_id());
}

size_t edge::get_my_id() const
{
    return my_id_;
}

//triangle * edge::get_triangle() const
//{
//    size_t a = get_vertex_id();
//    size_t b = next()->get_vertex_id();
//    size_t c = next()->next()->get_vertex_id();
//    
//    return new triangle(a, b, c);
//}


