
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

void solveTask(std::multimap<short int, std::string>& yearSurname)
{
    std::pair<short int, std::string> temp;
    for (const auto& pair: yearSurname)
        std::cout << pair.first << ' ' << pair.second << '\n';
}

int main()
{
    short int year;
    std::string surname;
    std::multimap<short int, std::string> yearSurname;
    while(std::cin >> year >> surname)
        yearSurname.insert(std::make_pair(year, surname));
    solveTask(yearSurname);
}