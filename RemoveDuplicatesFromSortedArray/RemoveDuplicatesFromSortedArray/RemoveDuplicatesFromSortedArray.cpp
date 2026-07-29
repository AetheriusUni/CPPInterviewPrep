/*
Given a sorted integer array, remove the duplicates from the array.
Return the length of the new array.
*/

#include <iostream>
#include <iterator>

int removeDuplicates(int arr[], int sizeOfArray)
{
	// index in arr[] which we want to compare to as the previous value
	// this also points to the index of where our last seen unique value was placed
	int i = 0;

	// for each of the elements starting with the one in the 1 index
	for (int j = 1; j < sizeOfArray; j++)
	{
		// if we run into a different value
		if (arr[i] != arr[j])
		{
			// place that value in the next slot
			arr[i + 1] = arr[j];
			// now we look at this new value as the most recently seen unique value to compare against
			i++;
		}
	}

	// since the index of the last element is 1 below the size of the array due to 0-indexing, return i+1
	// since an array with the last index as 2 has a size of 3, for example
	return i + 1;
}

int main()
{
	int arr[] = { 1, 1, 2, 2, 2, 3, 3 };
	int sizeOfArray = std::size(arr);
	int newArraySize = removeDuplicates(arr, sizeOfArray);

	std::cout << newArraySize << std::endl;
}

// Time Complexity: O(n) since we go through each of the elements once