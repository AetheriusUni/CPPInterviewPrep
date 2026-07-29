// Check if array is sorted
// Time Complexity O(n)

#include <iostream>
#include <iterator>

// must pass in size of the array as a separate argument since at this time the arr is a pointer to the first element of arr
// this is array decay, so we must get the size of the array before it's passed in to this function and have the sizeOfArray argument
bool isArraySorted(int arr[], int sizeOfArray)
{
	for (int i = 1; i < sizeOfArray; i++)
	{
		// array is not sorted if the previous element is bigger than the current one
		if (arr[i] < arr[i - 1])
		{
			return false;
		}
	}

	return true;
}

int main()
{
	// sorted array -> TRUE
	int arrOne[] = { 1, 2, 2, 3, 3, 4 };
	int sizeOne = std::size(arrOne);
	// unsorted array -> FALSE
	int arrTwo[] = { 1, 2, 1, 3, 4 };
	int sizeTwo = std::size(arrTwo);

	std::cout << std::boolalpha << isArraySorted(arrOne, sizeOne) << std::endl;
	std::cout << std::boolalpha << isArraySorted(arrTwo, sizeTwo) << std::endl;
	return 0;
}