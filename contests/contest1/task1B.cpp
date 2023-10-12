#include <iostream>
#include <vector>
#include <cmath>

void stylishClothes(const std::vector<int>& tshirtsColours, const std::vector<int>& pantsColours)
{
    int minimal = 10000000;
    int tshirtAnswer = tshirtsColours[0];
    int pantsAnswer = pantsColours[0];

    size_t iteratorStartShirts = 0;
    size_t iteratorStartPants = 0;

    while (iteratorStartShirts < tshirtsColours.size() && iteratorStartPants < pantsColours.size())
    {
        int diff = std::abs(tshirtsColours[iteratorStartShirts] - pantsColours[iteratorStartPants]);

        if (diff == 0)
        {
            tshirtAnswer = tshirtsColours[iteratorStartShirts];
            pantsAnswer = pantsColours[iteratorStartPants];
            break;
        }

        if (diff < minimal)
        {
            minimal = diff;
            tshirtAnswer = tshirtsColours[iteratorStartShirts];
            pantsAnswer = pantsColours[iteratorStartPants];
        }

        if (tshirtsColours[iteratorStartShirts] < pantsColours[iteratorStartPants])
            ++iteratorStartShirts;
        else
            ++iteratorStartPants;
    }

    std::cout << tshirtAnswer << ' ' << pantsAnswer;
}

int main()
{
    int numberOfTShirts, numberOfPants, colour;
    std::cin >> numberOfTShirts;
    std::vector<int> tshirtsColours(numberOfTShirts);

    for (int i = 0; i < numberOfTShirts; ++i)
    {
        std::cin >> colour;
        tshirtsColours[i] = colour;
    }

    std::cin >> numberOfPants;
    std::vector<int> pantsColours(numberOfPants);

    for (int i = 0; i < numberOfPants; ++i)
    {
        std::cin >> colour;
        pantsColours[i] = colour;
    }

    stylishClothes(tshirtsColours, pantsColours);
    return 0;
}
