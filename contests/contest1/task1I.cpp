#include <iostream>
#include <vector>

void heapify(std::vector<long long>& heap, int size, long long currentRoot)
{
    long long largest = currentRoot;
    long long left = 2 * currentRoot + 1;
    long long right = 2 * currentRoot + 2;

    // тут просто проверяю какой из детей больше
    if (left < size && heap[left] > heap[largest])
        largest = left;
    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != currentRoot) // если нашли больший элемент чем наш то надо опять бахнуть кучу и проверить ее
    {
        std::swap(heap[currentRoot], heap[largest]);
        heapify(heap, size, largest);
    }
}


void deleteRoot(std::vector<long long>& arr, int& n)
{
    long long lastEl = arr[n - 1];
    arr[0] = lastEl; // удаляю максимальный эл (корень главный) просто ставя его на последнее место
    --n; // и делаю массив меньше
    heapify(arr, n, 0);
}

int main()
{
    std::string operation;
    std::vector<long long> vec;
    int sizeOfVec = 0;

    while (std::cin >> operation)
    {
        if (operation == "ADD")
        {
            long long num;
            std::cin >> num;
            vec.push_back(num);
            int index = sizeOfVec;
            ++sizeOfVec;
            // проверяю если родитель меньше тек элемента то меняем их (ну по сути строю кучу)
            while (index > 0 && vec[index] > vec[(index - 1) / 2])
            {
                std::swap(vec[index], vec[(index - 1) / 2]);
                index = (index - 1) / 2;
            }
        }
        else if (operation == "EXTRACT")
        {
            if (sizeOfVec > 0)
            {
                std::cout << vec[0] << '\n';
                deleteRoot(vec, sizeOfVec);
            }
            else
                std::cout << "CANNOT" << '\n';
        }
        else if (operation == "CLEAR")
        {
            vec.clear();
            sizeOfVec = 0;
        }
    }
}