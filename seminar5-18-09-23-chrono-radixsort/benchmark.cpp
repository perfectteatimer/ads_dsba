#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <algorithm>

#include <functional>
#include <chrono>

//***********************************************************

void bubblesort(std::vector<int>& v)
{
    for (int i = 0; i < v.size() - 1; i++)
        for (int j = 0; j < v.size() - 1; j++)
            if (v[j] > v[j + 1])
                std::swap(v[j], v[j+1]);
}

//***********************************************************

void merge2(std::vector<int>& v, int l, int c, int r)
{
    int n = r - l + 1;

    std::vector<int> tmp(n, 0);

    int i = l, j = c + 1;

    for (int k = 0; k < n; k++)
    {
        if (i > c)
            tmp[k] = v[j++];
        else if (j > r)
            tmp[k] = v[i++];
        else
            tmp[k] = v[i] < v[j] ? v[i++] : v[j++];
    }

    for (int i = l, k = 0; k < n; i++, k++)
        v[i] = tmp[k];
}

void mergesort2(std::vector<int>& v, int l, int r)
{
    if(l >= r)
        return;

    int c = l + (r - l)/2;

    mergesort2(v, l, c);
    mergesort2(v, c + 1, r);

    merge2(v, l, c, r);
}

void mergesort(std::vector<int>& v)
{
    return mergesort2(v, 0, v.size() - 1);
}

//***********************************************************

// Generates a random vector of n elements in the range [a,b]
std::vector<int> genRandomVector(int a, int b, int n)
{
    std::vector<int> tmp(n, 0);

    std::random_device randDev;
    std::mt19937 rng(randDev()); // Random number generator

    std::uniform_int_distribution<int> uniformDistr(a,b);

    for (int i = 0; i < n; i++)
        tmp[i] = uniformDistr(rng);

    return tmp;
}

//***********************************************************

using SortFunction = std::function<void(std::vector<int>&)>;

void benchmark(std::string& benchmarkName, std::vector<int> v, SortFunction& sortFunc)
{
    const int NUM_RUNS = 10;

    double accumTime = 0;

    for (int i = 0; i < NUM_RUNS; i++)
    {
        std::vector<int> tmpVec(v); // clone the vector to make it sort each time

        auto startTime = std::chrono::system_clock::now();

        sortFunc(tmpVec);

        auto endTime  = std::chrono::system_clock::now();

        // https://cplusplus.com/reference/chrono/nanoseconds
        auto sortTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);

        std::cout << benchmarkName << "," << i+1 << "," << sortTime.count() << std::endl;

        accumTime += sortTime.count();
    } 

    double avgTime = accumTime / (double) NUM_RUNS;

    std::cout << benchmarkName << ",average_time," << avgTime << std::endl;
}

//***********************************************************

int main()
{
    SortFunction mergesortFunc  = &mergesort;
    SortFunction bubblesortFunc = &bubblesort; 

    for (int n : {100, 10000, 100000})
    {
        std::vector<int> v = genRandomVector(0, 100, n); // generate N elements in range [0,0]

        std::string bmNameMergesort  = std::string("mergesort")  + std::to_string(n);
        std::string bmNameBubblesort = std::string("bubblesort") + std::to_string(n); 

        benchmark(bmNameMergesort,  v, mergesortFunc);
        benchmark(bmNameBubblesort, v, bubblesortFunc);
    }

    return 0;
}