//
//  triangulation.cpp
//  triangulation
//
//  Created by Dmitry Baev on 09.05.13.
//  Copyright (c) 2013 Dmitry Baev. All rights reserved.
//

#include "triangulation.h"
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "point.h"
#include "data_struct.h"

void triangulation::add_vertex(size_t p_id)
{
    add_vertex(p_id, locate(*get_storage().get_point(p_id)));
}

void triangulation::add_vertex(size_t p_id, size_t nearest_id)
{
    switch (edges_.size())
    {
        case 0:
        {
            edges_.push_back(get_storage().get_inf_point_id());
        }
        case 1:
        {
            size_t n_edge_id = create_edge(p_id, NULL, edges_[0]);
            set_twin_by_id(edges_[0], n_edge_id);
            
            edges_.push_back(n_edge_id);
            break;
        }
        case 2:
        {
            size_t n1_edge_id = create_edge(p_id, edges_[0], NULL);
            size_t n2_edge_id = create_edge(p_id, edges_[1], NULL);
            
            size_t n1t_edge_id = create_edge(get_vertex_id(edges_[0]), n2_edge_id, n1_edge_id);
            set_twin_by_id(n1_edge_id, n1t_edge_id);
            
            size_t n2t_edge_id = create_edge(get_vertex_id(edges_[1]), n1_edge_id, n2_edge_id);
            set_twin_by_id(n2_edge_id, n2t_edge_id);
            
            edges_.push_back(n1_edge_id);
            edges_.push_back(n1t_edge_id);
            edges_.push_back(n2_edge_id);
            edges_.push_back(n2t_edge_id);
            
            break;
        }
        default:
        {
            break;
        }
    }

}

size_t triangulation::locate(const point p) const
{
    srand(static_cast<unsigned int>(time(NULL)));
    return locate(p, edges_[rand() % edges_.size()]);
}

size_t triangulation::locate(const point p, size_t nearest_id) const
{
    //remove this code 
    return edges_[rand() % edges_.size()];
}