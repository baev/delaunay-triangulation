//
//  point.h
//  triangulation
//
//  Created by Dmitry Baev on 09.05.13.
//  Copyright (c) 2013 Dmitry Baev. All rights reserved.
//

#ifndef __triangulation__mpoint__
#define __triangulation__mpoint__

#include <iostream>
#include <gmp.h>
#include <gmpxx.h>
#include <fstream>
#include "cg/io/point.h"

//#define mpf_class double
//#define mpq_class double

using cg::point_2f;

struct mpoint
{
    
    mpoint(const mpf_class xx, const mpf_class yy);
    mpoint(const double xx, const double yy);
    mpoint(const point_2f);
    
    mpoint operator-() const;

    mpoint operator+(const mpoint &other) const;
    mpoint operator-(const mpoint &other) const;
    
    bool operator==(const mpoint &other) const;
    bool operator!=(const mpoint &other) const;
    
    mpf_class x() const;
    mpf_class y() const;
    mpf_class z() const;
    
    friend mpoint * get_inf_point();
    
    friend std::istream &operator>>(std::istream &in, mpoint &);
    friend std::ostream &operator<<(std::ostream &out, const mpoint &);
    
private:
    mpoint(mpf_class xx, mpf_class yy, mpf_class zz);
    
    double x_;
    double y_;
    double z_;
};

#endif /* defined(__triangulation__mpoint__) */
