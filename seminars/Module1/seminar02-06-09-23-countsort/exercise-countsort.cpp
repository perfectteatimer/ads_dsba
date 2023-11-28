#include <iostream>
#include <vector>
#include <string>

struct Employee
{
	// assume grades from 0 to 5
	int grade;

	std::string name;
};

// Code countsort algorithm to sort employees according to their grade

int main()
{
	std::vector<Employee> a =
	{
		{2, "John"},
		{5, "Jean"},
		{3, "Michael"},
		{0, "Steven"},
		{2, "Harry"},
		{3, "Peter"},
		{0, "Sam"},
		{3, "Michelle"}
	};

	std::vector<Employee> b = countsort(a);

	for (Employee& e : b)
		std::cout << e.grade << ',' << e.name << std::endl;

	/* output:
		0 Steven
		0 Sam
		2 John
		2 Harry
		3 Michael
		3 Peter
		3 Michelle
		5 Jean
	*/

	return 0;
}