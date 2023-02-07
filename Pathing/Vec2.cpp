//
// Created by alpat on 07.02.2023.
//

#include "Vec2.h"
#include <cmath>


float Vec2::DistTo(const Vec2 &other) const
{
    return (*this - other).Length();
}
float Vec2::Length() const
{
    return sqrt(x*x + y*y);
}
Vec2 Vec2::operator-(const Vec2& other) const
{
    Vec2 out;
    out.x = x - other.x;
    out.y = y - other.y;
    return out;
}
bool Vec2::operator==(const Vec2&other) const
{
    return x == other.x and y == other.y;
}
bool Vec2::operator!=(const Vec2 &other) const
{
    return !(*this == other);
}