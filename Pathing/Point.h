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
        std::vector<size_t> m_vNeighbors;
        [[nodiscard]] float GetHeruistic(const Point& start, const Point& end ) const
        {
            return m_vecOrigin.DistTo(start.m_vecOrigin) + m_vecOrigin.DistTo(end.m_vecOrigin);
        }
        Point(const Vec2& vec, const std::vector<size_t>& neighbors)
        {
            m_vecOrigin = vec;
            m_vNeighbors = neighbors;
        }
        bool operator==(const Point& other) const
        {
            if (this == &other)
                return true;

            return m_vecOrigin == other.m_vecOrigin;
        }
        bool operator!=(const Point& other) const
        {
            return !(*this == other);
        }
    };

} // Pathing
