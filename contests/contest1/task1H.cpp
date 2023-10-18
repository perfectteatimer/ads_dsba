#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

void sortFractions(std::vector<long>& A, std::vector<long>& B, std::vector<int>& vecIndexes)
{
    std::vector<std::pair<long, long>> fractions;
    for (size_t i = 0; i < A.size(); ++i)
    {
        for (size_t j = 0; j < B.size(); ++j)
        {
            long gcdOfValues = std::gcd(A[i], B[j]);
            fractions.emplace_back(A[i] / gcdOfValues, B[j] / gcdOfValues); // делю на нод чтобы дробь была несократимой ваще
        }
    }
    // сортирую по итогу деления числитель/знаменатель. перевожу в double чтобы сравнивать числа не только по целому значению
    std::sort(fractions.begin(), fractions.end(), [](const auto& lhs, const auto& rhs)
    {
        return static_cast<double>(lhs.first) / lhs.second < static_cast<double>(rhs.first) / rhs.second; // пришлось вспомнить что такое компаратор
    });

    std::vector<std::pair<long, long>> answerFractions;
    for (int index : vecIndexes)
        answerFractions.push_back(fractions[index - 1]); // индексы начинаются с 1 поэтому вычитаем 1 чтобы вставить нужные значения

    for (const auto& el : answerFractions)
        std::cout << el.first << ' ' << el.second << '\n';
}

int main()
{
    int n, q;
    std::cin >> n >> q;
    std::vector<long> vecA(n);
    std::vector<long> vecB(n);
    std::vector<int> vecIndexes(q);
    for (int i = 0; i < n; ++i)
        std::cin >> vecA[i];
    for (int i = 0; i < n; ++i)
        std::cin >> vecB[i];
    for (int i = 0; i < q; ++i)
        std::cin >> vecIndexes[i];
    sortFractions(vecA, vecB, vecIndexes);
}
