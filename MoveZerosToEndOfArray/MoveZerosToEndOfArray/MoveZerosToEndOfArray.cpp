#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

// brute force with sorting
// Time Complexity O(2n)
// Space Complexity O(1)
std::vector<int> moveZerosToEndSorting(std::vector<int> arr)
{
	// sort the array
	std::sort(arr.begin(), arr.end());
	// then reverse it
	std::reverse(arr.begin(), arr.end());

	return arr;
}

// brute force without sorting
// Time Complexity O(2n) since we have O(n) + O(x) + O(n - x)
// Space Complexity O(1)
std::vector<int> moveZerosToEnd(std::vector<int> arr)
{
	// hold all the non-zero values in a separate vector
	std::vector<int> nonZeroHolder;
	// Time Complexity O(n)
	// Space Complexity O(x) where x is the number of nonzero elements
	// Space Complexity Worst Case O(n) if each element is non-zero
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] != 0)
		{
			nonZeroHolder.push_back(arr[i]);
		}
	}

	// place the non-zero values in the first indices of arr
	// O(x)
	// in the worst case this is O(n) when all elements are non-zero
	// we could make a check for if nonZeroHolder.size() == arr.size() then just return arr immediately
	for (int i = 0; i < nonZeroHolder.size(); i++)
	{
		arr[i] = nonZeroHolder[i];
	}

	// populate array after non-zero value with all zeros
	// O(n - x) since we only go through the non-zero values
	for (int i = nonZeroHolder.size(); i < arr.size(); i++)
	{
		arr[i] = 0;
	}

	return arr;
}

// optimal
// Time Complexity O(n)
// Space Complexity O(1) since we're not using any extra space and are modifying the original array
std::vector<int> moveZerosToEndOptimal(std::vector<int> arr)
{
	// holds the index of the last seen zero
	int lastZeroTracker = -1;

	// find the first zero
	// O(x) where x is the index of the first zero
	// the worst case would be O(n) if the first zero is the last zero or if there is no zero
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] == 0)
		{
			lastZeroTracker = i;
			break;
		}
	}

	// if there are no zeros there's nothing to be done
	if (lastZeroTracker == -1)
	{
		return arr;
	}

	// for the rest of the array starting at the index after the one of the first zero
	// O(n - x) since we're looking at every element after the first zero
	for (int i = lastZeroTracker + 1; i < arr.size(); i++)
	{
		// if we run into a non-zero number
		if (arr[i] != 0)
		{
			// swap places between that non-zero number and the last seen zero
			std::swap(arr[i], arr[lastZeroTracker]);
			// then move the lastZeroTracker to the right 
			lastZeroTracker++;
		}
	}
	
	return arr;
}

int main()
{
	std::vector<int> arr = { 1, 0, 2, 3, 2, 0, 0, 4, 5, 1 };
	//std::vector<int> zerosAtEndArray = moveZerosToEndSorting(arr);
	//std::vector<int> zerosAtEndArray = moveZerosToEnd(arr);
	std::vector<int> zerosAtEndArray = moveZerosToEndOptimal(arr);

	for (int i = 0; i < arr.size(); i++)
	{
		std::cout << zerosAtEndArray[i] << " ";
	}

	return 0;
}