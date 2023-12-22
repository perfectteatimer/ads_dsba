#include <iostream>

int countSafeStacks(int n)
{
    if (n == 1) return 3;
    int lastA = 1, lastB = 1, lastC = 1;
    int currentA, currentB, currentC;
    for (int i = 2; i <= n; ++i)
    {
        currentA = lastB + lastC; // 'a' can only follow 'b' or 'c'
        currentB = lastA + lastB + lastC; // 'b' can follow any type
        currentC = lastA + lastB + lastC; // 'b' can follow any type
        lastA = currentA;
        lastB = currentB;
        lastC = currentC;
    }

    return lastA + lastB + lastC; // total safe
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << countSafeStacks(n);
}
