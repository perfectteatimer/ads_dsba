#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <algorithm>

#include <functional>
#include <chrono>
#include <cmath>

//***********************************************************

void radixsort(std::vector<int>& v, int d)
{


}

//***********************************************************

void benchmark(std::vector<int> v, int d)
{

}

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

int main()
{
	// Task #1: Code radixsort and tests that it works
	std::vector<int> v = {329, 457, 657, 839, 436, 720, 355};

	radixsort(v, 3);

	for (int x : v)
		std::cout << x << ' ';
	std::cout << std::endl;

	// Task#2: Generate vector with elements in a range, e.g., [10000, 99999]
	// with all elements having the same number of digits
	// and tests the average time for N = 100K, 1M, 10M

	return 0;
}