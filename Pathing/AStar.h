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

        [[nodiscard]] std::list<Vec2> FindPath(const Vec2& start, const Vec2& end) const;
    private:
        struct Node
        {
            Node( const Point&  pPoint,  const Node* pParent) : m_pPoint(pPoint)
            {
                m_pParent = pParent;
            }
             const Point& m_pPoint;
             const Node* m_pParent;
        };
        [[nodiscard]] const Point& GetClosestPoint(const Vec2& cord) const;
        [[nodiscard]] static std::list<Node>::const_iterator GetTheBestPoint(const std::list<Node>& publicList, const Point& startPoint, const Point& endPoint);
        std::vector<Point> m_listPoints;
        static bool FindPointInNodeList(const std::list<Node>& list, const Point& pPoint);
        static bool IsPointInPublicOrPrivateList(const std::list<Node>& publicList, const std::list<Node>& privateList, const Point& point);
        void AddNotVisitedPointNeighboursIntoPublicList(std::list<Node>& publicList,const std::list<Node>& privateList) const;
    };

} // Pathing
