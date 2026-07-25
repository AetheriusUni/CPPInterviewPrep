// print from N to 1
// if n = 3, print 3 2 1
// usage of function (i - 1, n) not allowed
// usage of function (i + 1, n) allowed

#include <iostream>

void printNToOne (int i, int n)
{
	// base case, if this is true we start to return all the prior recursive calls
	if (i > n)
	{
		return;
	}
	// putting the print statement after the recursive call means to start printing only after one instance of recursion hits the return in the base case
	printNToOne(i + 1, n);
	std::cout << i << " ";
	/*
	// this would cause the print to be from i to n instead
	std::cout << i << " ";
	printNToOne(i + 1, n); // should be renamed to printOneToN
	*/
}

int main()
{
	int i = 1;
	int n = 3;

	printNToOne(i, n);

	return 0;
}