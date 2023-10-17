#include <iostream>
#include <vector>
#include <algorithm>

void countSort(std::vector<int>& v)
{
    int minElement = *std::min_element(v.begin(), v.end());
    int maxElement = *std::max_element(v.begin(), v.end());

    std::vector<int> countVector(maxElement - minElement + 1, 0);
    for (int num : v)
        ++countVector[num - minElement]; // превращаю отрицательные в положительные (тк индексы не могут быть -)
    std::vector<int> answerVector;
    for (int i = 0; i < countVector.size(); ++i)
    {
        while (countVector[i] > 0)
        {
            answerVector.push_back(i + minElement); // возвращаю таким образом отрицательные числа на базу
            --countVector[i];
        }
    }
    for (int el : answerVector)
        std::cout << el << ' ';
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> vec[i];
    }
    countSort(vec);
}
