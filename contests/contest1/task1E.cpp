#include <iostream>
#include <vector>

void SelectionSort(std::vector<int>& A)
{
    for (size_t i = 0; i < A.size(); ++i)
    {
        int maximalIndex = i;
        for (size_t j = i + 1; j < A.size(); ++j)
        {
            if (A[maximalIndex] < A[j])
            {
                maximalIndex = j;
            }
        }
        if (maximalIndex != i)
        {
            std::swap(A[i], A[maximalIndex]);
        }
    }
    for (auto el: A)
    {
        std::cout << el << ' ';
    }
}



int main()
{
    std::vector<int> array;
    int value;
    while (std::cin >> value)
    {
        array.push_back(value);
    }
    SelectionSort(array);
}
