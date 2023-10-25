// в задаче не сказано ниче про деревья или тому подобное => можно делать как вздумается (я надеюсь)
#include <iostream>
#include <map>

void addElement(std::map<int, int>& arr, int index, int value)
{
    index--;
    arr[index] = value;
}

void deleteElement(std::map<int, int>& arr, int index)
{
    index--;
    arr.erase(index);
}

void printResult(const std::map<int, int>& arr)
{
    std::cout << arr.size() << '\n';
    for (const auto& [index, value] : arr) {
        std::cout << value << " ";
    }
    std::cout << '\n';
}

int main() {
    int lengthOfArr, numberOfRequests;
    std::cin >> lengthOfArr >> numberOfRequests;

    std::map<int, int> arr;
    for (int i = 0; i < lengthOfArr; ++i) {
        int value;
        std::cin >> value;
        arr[i] = value;
    }

    for (int i = 0; i < numberOfRequests; ++i) {
        std::string command;
        std::cin >> command;
        if (command == "add") {
            int index, value;
            std::cin >> index >> value;
            addElement(arr, index, value);
        } else if (command == "del") {
            int index;
            std::cin >> index;
            deleteElement(arr, index);
        }
    }

    printResult(arr);
}
