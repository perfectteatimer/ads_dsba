//
// Created by roman bokhyan on 11.10.2023.
//

#include <iostream>
#include <vector>
#include <algorithm>

void solveTask(std::vector<std::pair<short int, std::string>>& yearSurname)
{
    std::pair<short int, std::string> temp;
    for (size_t i = 0; i < yearSurname.size() - 1; i++)
    {
        if (yearSurname[i].first > yearSurname[i + 1].first)
        {

        }
    }
    for (auto i: yearSurname)
        std::cout << i.first << ' ' << i.second << '\n';
}


int main()
{
    short int year;
    std::string surname;
    std::vector<std::pair<short int, std::string>> yearSurname;
    while(std::cin >> year >> surname)
    {
        yearSurname.push_back(std::make_pair(year, surname));
    }
    solveTask(yearSurname);

}