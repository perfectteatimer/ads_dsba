#include <iostream>

int countSafeStacks(int n)
{
    if (n == 1) return 2;
    std::pair<int, int> last = {1, 1};
    std::pair<int, int> current;
    for (int i = 2; i <= n; ++i)
    {
        current.first = last.first + last.second; //ending with 'B'
        current.second = last.first; //  ending with 'A'
        last = current; //for the next iteration
    }
    return current.first + current.second; // total safe
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << countSafeStacks(n);
}
