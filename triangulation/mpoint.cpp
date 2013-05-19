//
//  point.cpp
//  triangulation
//
//  Created by Dmitry Baev on 09.05.13.
//  Copyright (c) 2013 Dmitry Baev. All rights reserved.
//

#include "mpoint.h"

mpoint::mpoint(const double xx, const double yy)
:x_(xx), y_(yy), z_(1)
{  
}

mpoint::mpoint(const mpf_class xx, const mpf_class yy)
:x_(xx.get_d()), y_(yy.get_d()), z_(1)
{
}

mpoint::mpoint(const mpf_class xx, const mpf_class yy, const mpf_class zz)
:x_(xx.get_d()), y_(yy.get_d()), z_(zz.get_d())
{
}

mpoint::mpoint(const cg::point_2f p)
:x_(p.x), y_(p.y), z_(1)
{
}

mpoint mpoint::operator-() const
{
    return mpoint(-x_, -y_);
}

mpoint mpoint::operator+(const mpoint &other) const
{
    return mpoint(x_ + other.x_, y_ + other.y_);
}

mpoint mpoint::operator-(const mpoint &other) const
{
    return *this + (-other);
}

bool mpoint::operator==(const mpoint &other) const
{
    return x_ == other.x()
        && y_ == other.y()
        && z_ == other.z();
}

bool mpoint::operator!=(const mpoint &other) const
{
    return !(*this == other);
}

mpf_class mpoint::x() const
{
    return x_;
}

mpf_class mpoint::y() const
{
    return y_;
}

mpf_class mpoint::z() const
{
    return z_;
}

mpoint * get_inf_point()
{
    return new mpoint(0, 0, 0);
}

std::istream& operator>>(std::istream &in, mpoint &p)
{
    return in >> p.x_ >> p.y_;
}

std::ostream& operator<<(std::ostream &out, const mpoint &p)
{
    return out << p.x() << " " << p.y() << " " << p.z();
}