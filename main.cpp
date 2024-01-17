#include <vector>
#include <iostream>

int main()
{
    std::vector<int> v{3, 5, 5, 7};
    for (auto i = v.begin(); i < v.end(); ++i)
        std::cout<<*i;
}