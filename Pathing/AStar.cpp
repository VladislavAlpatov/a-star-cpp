//
// Created by alpat on 07.02.2023.
//

#include "AStar.h"
#include <algorithm>
#include <stdexcept>


namespace Pathing
{
    const Point& AStar::GetClosestPoint(const Vec2 &cord) const
    {
        return *std::min_element(m_listPoints.begin(), m_listPoints.end(), [cord](const Point& a, const Point& b)
        {
            return a.m_vecOrigin.DistTo(cord) < b.m_vecOrigin.DistTo(cord);
        });

    }

    std::list<Vec2> AStar::FindPath(const Vec2 &start, const Vec2 &end) const
    {
        const auto& startPoint = GetClosestPoint(start);
        const auto& endPoint   = GetClosestPoint(end);

        std::list<Node> publicList = { {startPoint, nullptr} };
        std::list<Node> privateList;


        do
        {
            if (publicList.empty())
                throw std::runtime_error("No path");

            const auto& bestTargetNode = GetTheBestPoint(publicList, startPoint, endPoint);


            privateList.push_back(*bestTargetNode);
            publicList.erase(bestTargetNode);

            AddNotVisitedPointNeighboursIntoPublicList(publicList, privateList);
        }
        while (privateList.back().m_pPoint != endPoint);
        std::list<Vec2> finalPath;

        for (const auto* pNext = &privateList.back(); pNext; pNext = pNext->m_pParent)
            finalPath.push_front(pNext->m_pPoint.m_vecOrigin);

        return finalPath;
    }

    bool AStar::FindPointInNodeList(const std::list<Node> &list, const Point& pPoint)
    {
        return std::find_if(list.begin(), list.end(), [&](const Node& val) -> bool {return val.m_pPoint == pPoint;}) != list.end();
    }

    AStar::AStar(const std::vector<Point> &points)
    {
        m_listPoints = points;
    }

    std::list<AStar::Node>::const_iterator AStar::GetTheBestPoint(const std::list<Node> &publicList, const Point &startPoint, const Point &endPoint)
    {
        return std::min_element(publicList.begin(), publicList.end(),
        [&startPoint, &endPoint](const Node& a, const Node& b) -> bool
              {
                return a.m_pPoint.GetHeruistic(startPoint, endPoint) < b.m_pPoint.GetHeruistic(startPoint, endPoint);
              });
    }

    bool AStar::IsPointInPublicOrPrivateList(const std::list<Node> &publicList, const std::list<Node> &privateList, const Point &point)
    {
        return FindPointInNodeList(publicList, point) or FindPointInNodeList(privateList, point);
    }

    void
    AStar::AddNotVisitedPointNeighboursIntoPublicList(std::list<Node> &publicList, const std::list<Node> &privateList) const
    {
        for (const auto iNeighbourId : privateList.back().m_pPoint.m_vNeighbors)
            if (!IsPointInPublicOrPrivateList(publicList, privateList, m_listPoints[iNeighbourId]))
                publicList.emplace_back(m_listPoints[iNeighbourId], &privateList.back());
    }
} // Pathing