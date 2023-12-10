#include <iostream>
#include <algorithm>

int expanding(const std::string& s, int L, int R)
{
    while (s[L] == s[R] && L >= 0 && R < s.length())
    {
        --L;
        ++R;
    }
    return R - L - 1; // возвращаем длину палиндрома
}

int numberOfPalindromes(const std::string& s)
{
    int count = 0;
    for (size_t i = 0; i < s.length(); ++i)
    {
        count += expanding(s, i, i) / 2; // для четной длинны уникальные палиндромы с центром i
        count += expanding(s, i, i + 1) / 2; // для нечетное длинны уникальные палиндромы между i i + 1
    }
    return count;
}

int main()
{
    std::ios_base::sync_with_stdio(false); //ускоряет код
    std::cin.tie(nullptr);
    std::string s;
    std::cin >> s;
    std::cout << numberOfPalindromes(s);
}
