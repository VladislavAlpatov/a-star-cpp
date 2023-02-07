//
// Created by alpat on 07.02.2023.
//

#pragma once


class Vec2
{
public:
    float x,y;
    Vec2() {x = 0.f; y = 0.f;};
    Vec2(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
    float DistTo(const Vec2& other) const;
    float Length() const;
    Vec2 operator-(const Vec2& other) const;
    bool operator==(const Vec2&other) const;
    bool operator!=(const Vec2& other) const;
};