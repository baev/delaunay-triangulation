//
//  lds.h
//  triangulation
//
//  Created by Dmitry Baev on 09.05.13.
//  Copyright (c) 2013 Dmitry Baev. All rights reserved.
//

#ifndef __triangulation__lds__
#define __triangulation__lds__

#include <iostream>
#include <vector>
#include <list>
#include "tds.h"


//chance add vertix to next level in percent
const mpf_class MAGIC_CONST = 16;


struct lds {
    lds();
    
    void add_vertex(const mpoint p);
    std::list<edge *> locate(const mpoint p) const;
    
    std::vector<edge> get_edges();
//    bool contains(const point p) const;
    
private:
    std::vector<tds *> lds_;
};

#endif /* defined(__triangulation__lds__) */
