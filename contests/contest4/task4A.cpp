#include <iostream>

int64_t numberOfWays(int64_t numberOfSteps)
{
    if (numberOfSteps == 1 or numberOfSteps == 2)
        return numberOfSteps;
    if (numberOfSteps == 3)
        return 4;
    else
        return (numberOfWays(numberOfSteps - 1) +
        numberOfWays(numberOfSteps - 2) +
        numberOfWays(numberOfSteps - 3));
}

int main()
{
    int64_t numberOfSteps;
    std::cin >> numberOfSteps;
    std::cout<<numberOfWays(numberOfSteps);
}
