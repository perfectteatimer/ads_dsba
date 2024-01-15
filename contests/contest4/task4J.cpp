#include <iostream>
#include <vector>
#include <climits>

int main()
{
    int len;
    std::cin >> len;
    std::vector<int> val(len);
    for (int i = 0; i < len; ++i)
    {
        std::cin >> val[i];
    }
    int sum = 0;
    int maxSum = INT_MIN;
    int maxStart = 0, maxEnd = 0, tempStart = 0;
    for (int i = 0; i < len; i++)
    {
        sum += val[i];
        if (sum > maxSum)
        {
            maxSum = sum;
            maxStart = tempStart;
            maxEnd = i;
        }
        if (sum < 0)
        {
            sum = 0;
            tempStart = i + 1;
        }
    }
    std::cout << maxStart + 1 << " " << maxEnd + 1 << " " << maxSum;
}


