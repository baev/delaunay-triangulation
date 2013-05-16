//
//  tds.cpp
//  tds
//
//  Created by Dmitry Baev on 09.05.13.
//  Copyright (c) 2013 Dmitry Baev. All rights reserved.
//

#include "tds.h"
#include "points_ds.h"

tds::tds()
{
    size_t inf = get_storage().get_inf_point_id();
    create_edge(inf, NULL, NULL);
}

edge * tds::create_edge(size_t vertex_id, edge *next, edge *twin)
{
    edge *res = new edge(vertex_id, next, twin);
    size_t id = storage_.get_id(res);
    res->set_my_id(id);
    edges_.push_back(id);

    return res;
}

void tds::add_vertex(size_t p_id, edge *nearest)
{
    switch (edges_.size())
    {
        case 0:
        {
            throw "something went wrong!!! empty edges_ array!!";
        }
        case 1:
        {
            edge *e0 = storage_.get_edge(edges_[0]);
            edge *e1 = create_edge(p_id, e0, e0);
            e0->set_next(e1);
            e0->set_twin(e1);
            return;
        }
        case 2:
        {
            
            edge *e0 = storage_.get_edge(edges_[0]);
            edge *e0t = storage_.get_edge(edges_[1]);
            
            edge *e1 = create_edge(p_id, e0, NULL);
            edge *e2 = create_edge(p_id, e0t, NULL);
            
            edge *e1t = create_edge(e0->get_vertex_id(), e2, e1);
            edge *e2t = create_edge(e0t->get_vertex_id(), e1, e2);
            
            e0->set_next(e2t);
            e0t->set_next(e1t);
            
            e1->set_twin(e1t);
            e2->set_twin(e2t);

            return;
        }
        default:
        {
            edge *next_edge = nearest->next();
            edge *prev_edge = nearest->next()->next();
            
            
            edge *e1 = create_edge(p_id, nearest, NULL);
            edge *e2 = create_edge(p_id, next_edge, NULL);
            edge *e3 = create_edge(p_id, prev_edge, NULL);
            
            edge *e1t = create_edge(nearest->get_vertex_id(), e3, e1);
            edge *e2t = create_edge(next_edge->get_vertex_id(), e1, e2);
            edge *e3t = create_edge(prev_edge->get_vertex_id(), e2, e3);
            
            e1->set_twin(e1t);
            e2->set_twin(e2t);
            e3->set_twin(e3t);
            
            nearest->set_next(e2t);
            next_edge->set_next(e3t);
            prev_edge->set_next(e1t);
            
            flip(nearest);
            flip(next_edge);
            flip(prev_edge);
        }
    }
}

void tds::flip(edge * e1)
{
    if(is_flippy(e1))
    {
        edge *e2 = e1->next();
        edge *e3 = e2->next();
        
        edge *e1t = e1->twin();
        edge *e4t = e1t->next();
        edge *e5t = e4t->next();
        
//        edge *e2t = e2->twin();
//        edge *e3t = e3->twin();
        
        edge *e4 = e4t->twin();
//        edge *e5 = e5t->twin();
        
        edge *e6 = create_edge(e3->get_vertex_id(), e5t, NULL);
        edge *e6t = create_edge(e4->get_vertex_id(), e3, e6);
        
        e6->set_twin(e6t);
        
        e3->set_next(e4t);
        e4t->set_next(e6t);
        
        e5t->set_next(e2);
        e2->set_next(e6);
        
        e1->set_next(NULL);
        e1t->set_next(NULL);
        e1->set_twin(NULL);
        e1t->set_twin(NULL);
        
        flip(e4t);
        flip(e5t);
        
    }
}

bool tds::is_flippy(edge *e)
{
    if (edges_.size() < 6)
    {
        return false;
    }
    
    mpoint v1 = e->next()->v2();
    mpoint v2 = e->twin()->next()->v2();
    
    if (e->v1().z() > 0 && e->v2().z() == 0 && v1.z() > 0 && v2.z() > 0 && !turn_right(v2, e->v1(), v1))
    {
        return true;
    }
    
    if (e->v1().z() == 0 && e->v2().z() > 0 && v1.z() > 0 && v2.z() > 0 && !turn_right(v1, e->v2(), v2))
    {
        return true;
    }
    
    if (!(e->v1().z() > 0 && e->v2().z() > 0 && v1.z() > 0 && v2.z() > 0))
    {
        return false;
    }
    
    return (in_circle(e->v1(), v2, e->v2(), v1) || in_circle(e->v2(), v1, e->v1(), v2));
}

edge * tds::locate(const mpoint p) const
{
    return locate(p, storage_.get_edge(edges_[edges_.size() - 1])->get_vertex_id());
}

edge * tds::locate(const mpoint p, size_t nearest_id) const
{
    edge *nearest = storage_.get_edge_by_point_id(nearest_id);
    
    if (edges_.size() < 3)
    {
        return nearest;
    }
    
    size_t count = 0;
    while (count < 3)
    {
        if (turn_right(nearest->v1(), nearest->v2(), p))
        {
            count++;
            nearest = nearest->next();
        }
        else
        {
            count = 0;
            nearest = nearest->twin()->next();
        }
    }
    
    return nearest;
}

std::vector<edge> tds::edges() const
{
    std::vector<edge> res;
    for (size_t i = 0; i < edges_.size(); i++)
    {
        edge *e = storage_.get_edge(edges_[i]);
        if ((e->next() != 0) && (e->v1().z() != 0) && (e->v2().z() != 0))
        {
            res.push_back(*e);
        }
    }    
    return res;
}

bool turn_right(mpoint v1, mpoint v2, const mpoint p)
{
    mpf_class r = v1.x() * (v2.y() * p.z() - v2.z() * p.y())
                + v1.y() * (v2.z() * p.x() - v2.x() * p.z())
                + v1.z() * (v2.x() * p.y() - v2.y() * p.x());
    
    return r <= 0;
}

bool in_circle(mpoint a, mpoint b, mpoint c, const mpoint d)
{
    mpq_class a11(a.x() - d.x());
	mpq_class a12(a.y() - d.y());
	mpq_class a13(a11 * a11 + a12 * a12);
    
	mpq_class a21(b.x() - d.x());
	mpq_class a22(b.y() - d.y());
	mpq_class a23(a21 * a21 + a22 * a22);
    
	mpq_class a31(c.x() - d.x());
	mpq_class a32(c.y() - d.y());
	mpq_class a33(a31 * a31 + a32 * a32);
    
	mpq_class det(a11 * a22 * a33);
	det += a12 * a23 * a31;
	det += a13 * a21 * a32;
	det -= a13 * a22 * a31;
	det -= a12 * a21 * a33;
	det -= a11 * a23 * a32;
    
	return (det < 0);
}