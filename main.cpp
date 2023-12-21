#include <iostream>
#include <vector>

int cheap(std::vector<int>& v)
{
    // Implement your logic here
    // Example: return the minimum value in the vector
    int min_value = INT_MAX;
    for (int price : v) {
        if (price < min_value) {
            min_value = price;
        }
    }
    return min_value;
}

int main()
{
    int numbOfStairs, val;
    std::cin >> numbOfStairs;  // First, read the number of stairs
    std::vector<int> pricesOfStairs;
    pricesOfStairs.reserve(numbOfStairs); // Reserve memory for efficiency

    for (int i = 0; i < numbOfStairs; ++i)
    {
        std::cin >> val;
        pricesOfStairs.push_back(val);
    }

    std::cout << cheap(pricesOfStairs) << std::endl;  // Output the result of cheap
}
