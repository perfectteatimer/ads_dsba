#include <iostream>
#include <vector>

std::vector<int> minimizeTheNumberOfRepeatersUse(std::vector<int>& positionsOfHouses, int d)
{
    std::vector<int> repeaters;
    int lastCoveredHouse = 0; //  последний дом охваченный устройством

    for (int i = 0; i < positionsOfHouses.size();)
    {
        // установить передатчик на расстоянии d от текущего дома
        int repeaterPos = positionsOfHouses[i] + d;
        repeaters.push_back(repeaterPos);

        // переход к следующему дому находящемуся вне зоны действия текущего устройства
        while (i < positionsOfHouses.size() && positionsOfHouses[i] <= repeaterPos + d)
        {
            lastCoveredHouse = positionsOfHouses[i];
            i++;
        }

        // если следующий дом находится в диапазоне d от последнего охваченного дома - продолжаем без размещения нового устройства ретрансляции
        if (i < positionsOfHouses.size() && positionsOfHouses[i] <= lastCoveredHouse + d)
            continue;

        // если мы достигли конца - выйдите из цикла
        if (i >= positionsOfHouses.size())
            break;
    }

    return repeaters;
}

int main()
{
    std::vector<int> positionsOfHouses;
    int possibleCoverDiameter;
    int pos;

    while ((std::cin >> pos) && pos != -1)
        positionsOfHouses.push_back(pos);

    std::cin >> possibleCoverDiameter;
    std::vector<int> result = minimizeTheNumberOfRepeatersUse(positionsOfHouses, possibleCoverDiameter);

    for (int repeaterPos: result)
        std::cout << repeaterPos << " ";

}
