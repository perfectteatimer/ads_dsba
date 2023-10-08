#include "heap.h"
#include <iostream>

int main()
{
	std::vector<int> v = {9,1,8,2,7,3,6,4,5,0};

	heapsort(v);

	// should print sorted vector 0...9
	for (int x : v)
		std::cout << x << ' ';
	std::cout << std::endl;

	return 0;
}