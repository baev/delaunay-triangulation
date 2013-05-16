//
//  triangulation.h
//  triangulation
//
//  Created by Dmitry Baev on 09.05.13.
//  Copyright (c) 2013 Dmitry Baev. All rights reserved.
//

#ifndef __triangulation__tds__
#define __triangulation__tds__

#include <iostream>
#include <vector>
#include "edge.h"
#include "edges_ds.h"

struct tds {
    tds();
    
    void add_vertex(size_t p_id, edge *nearest);

    edge * locate(const mpoint p) const;
    edge * locate(const mpoint p, size_t nearest_id) const;
    
    std::vector<size_t> get_edges() const;
    
    edge * create_edge(size_t vertex_id, edge *next, edge *twin);
    
    std::vector<edge> edges() const;
    
    void flip(edge *e);
    bool is_flippy(edge *e);
    
private:
    
    std::vector<size_t> edges_;
    edges_ds storage_;
    
};

bool turn_right(mpoint v1, mpoint v2, const mpoint p);
bool in_circle(mpoint v1, mpoint v2, mpoint v3, const mpoint p);

#endif /* defined(__triangulation__tds__) */
