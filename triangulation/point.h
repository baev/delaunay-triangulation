//
//  point.h
//  triangulation
//
//  Created by Dmitry Baev on 09.05.13.
//  Copyright (c) 2013 Dmitry Baev. All rights reserved.
//

#ifndef __triangulation__point__
#define __triangulation__point__

#include <iostream>
#include <gmp.h>
#include <gmpxx.h>
#include <fstream>

struct point
{
    
    point(const mpf_class xx, const mpf_class yy);
    point(const double xx, const double yy);
    
    point operator-() const;

    point operator+(const point &other) const;
    point operator-(const point &other) const;
    
    bool operator==(const point &other) const;
    bool operator!=(const point &other) const;
    
    mpf_class get_x_coord() const;
    mpf_class get_y_coord() const;
    mpf_class get_z_coord() const;
    
    friend point * get_inf_point();
    
    friend std::istream &operator>>(std::istream &in, point &);
    friend std::ostream &operator<<(std::ostream &out, const point &);
    
private:
    point(mpf_class xx, mpf_class yy, mpf_class zz);
    
    mpf_class x_;
    mpf_class y_;
    mpf_class z_;
};

#endif /* defined(__triangulation__point__) */
