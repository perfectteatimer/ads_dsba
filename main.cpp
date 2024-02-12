#include <vector>
#include <iostream>

int main()
{
    int n, number;
    std::cin >> n;
    std::vector<int> arr;
    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> number;
        if (number % 2 == 0)
            arr.push_back(number);

    }

    for (int i = arr.size() - 1; i >= 0; --i)
        std::cout << arr[i] << '\n';
}

