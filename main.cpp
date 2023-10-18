#include <iostream>
#include <vector>

void heapify(std::vector<int>& heap, int size, int currentRoot)
{
    int largest = currentRoot;
    int left = 2 * currentRoot + 1;
    int right = 2 * currentRoot + 2;

    // тут просто проверяю какой из детей больше
    if (left < size && heap[left] > heap[largest])
        largest = left;
    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != currentRoot) // если нашли больший элемент чем наш, то надо опять бахнуть кучу и проверить ее
    {
        std::swap(heap[currentRoot], heap[largest]);
        heapify(heap, size, largest);
    }
}

void insert(std::vector<int>& arr, long long num)
{
    arr.push_back(num);
    int index = arr.size() - 1;
    // проверяю если родитель меньше тек элемента, то меняем их (ну по сути строю кучу)
    while (index > 0 && arr[index] > arr[(index - 1) / 2])
    {
        std::swap(arr[index], arr[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void deleteRoot(std::vector<int>& arr)
{
    int size = arr.size();
    if (size <= 1) {
        arr.pop_back();
        return;
    }
    arr[0] = arr[size - 1];
    arr.pop_back();
    heapify(arr, arr.size(), 0);
}

int main()
{
    std::string operation;
    std::vector<int> vec;

    while (std::cin >> operation)
    {
        if (operation == "ADD")
        {
            int num;
            std::cin >> num;
            insert(vec, num);
        }
        else if (operation == "EXTRACT")
        {
            if (!vec.empty())
            {
                std::cout << vec[0] << '\n';
                deleteRoot(vec);
            }
            else
                std::cout << "CANNOT" << '\n';
        }
        else if (operation == "CLEAR")
            vec.clear();
    }
}
