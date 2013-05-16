//
//  triangle.h
//  triangulation
//
//  Created by Dmitry Baev on 09.05.13.
//  Copyright (c) 2013 Dmitry Baev. All rights reserved.
//

#ifndef __triangulation__triangle__
#define __triangulation__triangle__

#include <iostream>
#include "mpoint.h"

struct triangle
{
    triangle(size_t a_id, size_t b_id, size_t c_id);

private:
    size_t point_a_id_;
    size_t point_b_id_;
    size_t point_c_id_;
};

#endif /* defined(__triangulation__triangle__) */
