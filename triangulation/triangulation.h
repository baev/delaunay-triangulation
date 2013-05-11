//
//  triangulation.h
//  triangulation
//
//  Created by Dmitry Baev on 09.05.13.
//  Copyright (c) 2013 Dmitry Baev. All rights reserved.
//

#ifndef __triangulation__triangulation__
#define __triangulation__triangulation__

#include <iostream>
#include "edge.h"
#include <vector>

struct triangulation {
    triangulation();
    
    void add_vertex(size_t p_id);
    void add_vertex(size_t p_id, size_t nearest_id);

    size_t locate(const point p) const;
    size_t locate(const point p, size_t nearest_id) const;
    
    std::vector<size_t> get_edges() const;
    
private:
    std::vector<size_t> edges_;
};

#endif /* defined(__triangulation__triangulation__) */
