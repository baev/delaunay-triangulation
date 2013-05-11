//
//  tds.h
//  triangulation
//
//  Created by Dmitry Baev on 09.05.13.
//  Copyright (c) 2013 Dmitry Baev. All rights reserved.
//

#ifndef __triangulation__tds__
#define __triangulation__tds__

#include <iostream>
#include <vector>
#include <list>
#include "triangulation.h"


//chance add vertix to next level in percent
const mpf_class MAGIC_CONST = 16;



struct tds {
    tds();
    
    void add_vertex(const point p);
    std::list<size_t> locate(const point p) const;
    bool contains(const point p) const;
    
private:
    std::vector<triangulation *> tds_;
};

#endif /* defined(__triangulation__tds__) */
