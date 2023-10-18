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

    if (largest != currentRoot) // если нашли больший элемент чем наш то надо опять бахнуть кучу и проверить ее
    {
        std::swap(heap[currentRoot], heap[largest]);
        heapify(heap, size, largest);
    }
}

void heapSort(std::vector<int>& array, int size)
{
    // строим дерево идем от последнего элемента у которого есть дети
    for (int i = size / 2 - 1; i >= 0; --i)
        heapify(array, size, i);
    // меняю корень с последним элементом
    for (int i = size - 1; i > 0; --i)
    {
        std::swap(array[0], array[i]);
        heapify(array, i, 0); // вызываю хипифай чтобы восстановит свойства
    }
}


int main()
{
    int sizeOfArray;
    std::cin >> sizeOfArray;
    std::vector<int> arr(sizeOfArray);
    int el;
    for (int i = 0; i < sizeOfArray; ++i)
    {
        std::cin >> el;
        arr[i] = el;
    }
    heapSort(arr, sizeOfArray);
    for (int el: arr)
        std::cout << el << " ";
}