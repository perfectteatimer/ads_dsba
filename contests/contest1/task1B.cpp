#include <iostream>
#include <vector>

void stylishClothes(std::vector<int> tshirtsColours, std::vector<int> pantsColours)
{
    int minimal = 1000000;
    size_t iteratorStartShirts = 0;
    size_t iteratorStartPants = 0;
    int tshirtAnswer, pantsAnswer;
    while (tshirtsColours.size() > iteratorStartShirts && pantsColours.size() > iteratorStartPants)
    {
        if (abs(tshirtsColours[iteratorStartShirts] - pantsColours[iteratorStartPants]) < minimal)
        {
            minimal = abs(tshirtsColours[iteratorStartShirts] - pantsColours[iteratorStartPants]);
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
    std::vector<int> tshirtsColours;
    std::vector<int> pantsColours;
    std::cin >> numberOfTShirts;
    int iteratorTS = 0;
    while (iteratorTS < numberOfTShirts && std::cin >> colour)
    {
        tshirtsColours.push_back(colour);
        ++iteratorTS;
    }
    int iteratorP = 0;
    std::cin >> numberOfPants;
    while (iteratorP < numberOfPants && std::cin >> colour)
    {
        pantsColours.push_back(colour);
        ++iteratorP;
    }
    stylishClothes(tshirtsColours, pantsColours);
    return 0;
}
