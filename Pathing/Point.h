//
// Created by alpat on 07.02.2023.
//

#pragma once
#include <vector>
#include "Vec2.h"

namespace Pathing
{

    class Point
    {
    public:
        Point() = default;
        Vec2 m_vecOrigin;
        bool m_bLocked = false;
        std::vector<size_t> m_vNeighbors;
        float GetHeruistic(const Point& start, const Point& end ) const
        {
            return m_vecOrigin.DistTo(start.m_vecOrigin) + m_vecOrigin.DistTo(end.m_vecOrigin);
        }
        Point(const Vec2& vec, const std::vector<size_t>& neighbors)
        {
            m_vecOrigin = vec;
            m_vNeighbors = neighbors;
        }
    };

} // Pathing
