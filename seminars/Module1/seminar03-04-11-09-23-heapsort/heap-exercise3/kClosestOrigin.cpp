#include <iostream>
#include <vector>

using Point = std::pair<int,int>;

// Returns in a vector the k points whose EUCLIDEAN DISTANCE is closest to the origin (0,0)
std::vector<Point> kClosest(std::vector<Point>& points, int k)
{
    // Implement your solution using the HEAP class
}

int main()
{
    std::vector<Point> points = { {8,9} , {1,1} , {0,1} , {10,20} };

    // Returns the two points closest to the origin {1,1} and {0,1}
    std::vector<Point> closestPoints = kClosest(points, 2);

    for (auto [px, py] : closestPoints)
        std::cout << px << ',' << py << std::endl;

    return 0;
}