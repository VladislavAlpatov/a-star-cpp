#include <cmath>
#include "Pathing/AStar.h"

using namespace Pathing;
int main()
{
    Point A({0, 0}, {8, 1, 3, 4}); // 0
    Point B({1, 1}, {2, 0}); // 1
    Point C({1, 2}, {1, 7}); // 2
    Point D({1, -1}, {0, 2}); // 3
    Point E({0.5, -1.2}, {5, 0}); // 4
    Point F({1.f, -1.5}, {6, 4}); // 5
    Point G({1, -2}, {}); // 6
    Point X({3, -2}, {6, 2}); // 7
    Point O({-1, -1}, {0}); // 8

    auto algo = AStar({A, B, C, D, E,F,G,X, O});
    for (const auto pos : algo.FindPath({0,0}, {3,-2}))
    {
        printf("%.2f|%.2f\n",pos.x, pos.y);
    }
}
