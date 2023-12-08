#include <iostream>
#include <vector>
#include <string>

void print(const std::vector<int>& ans)
{
    for(const int& el: ans)
        std::cout << el << " ";
}

void zFunction(int size, const std::vector<int>& word)
{
    std::vector<int> z(size);
    for (int i = 1, l = 0, r = 0; i < size; ++i)
    {
        if (i <= r)
        {
            z[i] = std::min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < size && word[z[i]] == word[i + z[i]])
        {
            ++z[i];
        }
        if (i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }
    print(z);
}

void constructWordFromPrefix(int size, const std::vector<int>& prefixFunction)
{
    std::vector<int> word(size, 0);// прост начало
    int nextChar = 1;     // след буква(уже цифра) ну будем сдвигать если они не совпадают
    for (size_t i = 1; i < size; ++i)
    {
        if (prefixFunction[i] == 0)
        {
            word[i] += nextChar; // если в преф функции 0 значит нужна след буква
            nextChar++; // сдвигаем букву
        }
        else
            // если не 0 значит смотрим на букву в позиции значения
            word[i] += word[prefixFunction[i] - 1];
    }
    zFunction(size, word);
}

int main()
{
    int n, val;
    std::cin >> n;
    std::vector<int> prefixF;
    for (size_t i = 0; i < n; ++i)
    {
           std::cin >> val;
           prefixF.push_back(val);
    }
    constructWordFromPrefix(n, prefixF);
}

