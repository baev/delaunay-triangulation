//
//  point.cpp
//  triangulation
//
//  Created by Dmitry Baev on 09.05.13.
//  Copyright (c) 2013 Dmitry Baev. All rights reserved.
//

#include "point.h"

point::point(const double xx, const double yy)
:x_(xx), y_(yy), z_(1)
{  
}

point::point(const mpf_class xx, const mpf_class yy)
:x_(xx), y_(yy), z_(1)
{
}

point::point(const mpf_class xx, const mpf_class yy, const mpf_class zz)
:x_(xx), y_(yy), z_(zz)
{
}

point point::operator-() const
{
    return point(-x_, -y_);
}

point point::operator+(const point &other) const
{
    return point(x_ + other.x_, y_ + other.y_);
}

point point::operator-(const point &other) const
{
    return *this + (-other);
}

bool point::operator==(const point &other) const
{
    return x_ == other.get_x_coord()
        && y_ == other.get_y_coord()
        && z_ == other.get_z_coord();
}

bool point::operator!=(const point &other) const
{
    return !(*this == other);
}

mpf_class point::get_x_coord() const
{
    return x_;
}

mpf_class point::get_y_coord() const
{
    return y_;
}

mpf_class point::get_z_coord() const
{
    return z_;
}

point * get_inf_point()
{
    return new point(1, 1, 0);
}

std::istream& operator>>(std::istream &in, point &p)
{
    return in >> p.x_ >> p.y_;
}

std::ostream& operator<<(std::ostream &out, const point &p)
{
    return out << p.get_x_coord() << p.get_y_coord();
}