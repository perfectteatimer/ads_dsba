#include <iostream>
#include <vector>

int main()
{
    int n = 0;
    std::vector<int> tSheerts;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int colour = 0;
        std::cin >> colour;
        tSheerts.push_back(colour);
    }

    int k = 0;
    std::vector<int> pants;
    std::cin >> k;
    for (int i = 0; i < k; ++i)
    {
        int colour = 0;
        std::cin >> colour;
        pants.push_back(colour);
    }

    int difference = 100000000;
    size_t itSheerts = 0;
    size_t itPants = 0;
    int answerSheets = tSheerts[0];
    int answerPants = pants[0];

    while (itPants < pants.size() and itSheerts < tSheerts.size())
    {
        int currentDifference = std::abs(tSheerts[itSheerts] - pants[itPants]);

        if (currentDifference == 0)
        {
            answerPants = pants[itPants];
            answerSheets = tSheerts[itSheerts];
            break;
        }

        if (currentDifference < difference)
        {
            answerSheets = tSheerts[itSheerts];
            answerPants = pants[itPants];
            difference = currentDifference;
        }

        if (pants[itPants] > tSheerts[itSheerts])
            itSheerts++;

        else
            itPants++;
    }

    std::cout << answerSheets << ' ' << answerPants;
}