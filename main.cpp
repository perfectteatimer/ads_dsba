#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

struct Suffix {
    size_t index;
    const char* suffix;
};

bool customComparator(const Suffix& lhv, const Suffix& rhv) {
    return std::strcmp(lhv.suffix, rhv.suffix) < 0;
}

std::vector<size_t> GetSuffixArray(const std::string& inputStr) {
    size_t tempSize = inputStr.size();
    std::vector<Suffix> suffixes(tempSize);

    for (size_t i = 0; i < tempSize; i++) {
        suffixes[i].index = i;
        suffixes[i].suffix = inputStr.c_str() + i;
    }

    std::sort(suffixes.begin(), suffixes.end(), customComparator);

    std::vector<size_t> result(tempSize);
    for (size_t i = 0; i < tempSize; i++)
        result[i] = suffixes[i].index;

    return result;
}

int main() {
    std::string inputStr;
    std::getline(std::cin, inputStr);

    std::vector<size_t> tempVec = GetSuffixArray(inputStr);

    for (auto& temp : tempVec)
        std::cout << temp + 1 << " ";

    return 0;
}
