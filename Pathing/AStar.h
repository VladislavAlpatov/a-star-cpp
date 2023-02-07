//
// Created by alpat on 07.02.2023.
//

#pragma once

#include "Point.h"
#include "Vec2.h"
#include <list>
namespace Pathing
{


    class AStar
    {
    public:
        AStar(const std::vector<Point>& points);

        std::list<Vec2> FindPath(const Vec2& start, const Vec2& end) const;
    private:
        struct Node
        {
            Node( const Point*  pPoint,  const Node* pParent)
            {
                m_pPoint  = pPoint;
                m_pParent = pParent;
            }
             const Point* m_pPoint;
             const Node* m_pParent;
        };
        const Point* GetClosestPoint(const Vec2& cord) const;
        std::vector<Point> m_listPoints;
        bool FindPointInNodeList(const std::list<Node>& list, const Point* pPoint) const;
    };

} // Pathing
