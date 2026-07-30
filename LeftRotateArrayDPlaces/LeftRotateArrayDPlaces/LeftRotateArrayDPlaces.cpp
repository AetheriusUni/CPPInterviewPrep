#include <iostream>
#include <vector>
#include <algorithm>

// brute force
// Time Complexity O(n + d)
// Space Complexity O(d) since we're storing d elements in the holdDElements vector
std::vector<int> leftRotateArrayDPlaces(std::vector<int> arr, int d)
{
	// assigning arr.size() to a const variable since we use it a bunch here and doesn't change
	const int n = arr.size();
	// keeps d within the bounds of the size of the array
	// since rotating an array by the size of the array doesn't result in a change
	d = d % n;
	
	// hold d elements to be placed starting at the index after the d right-most elements are shifted to the left
	std::vector<int> holdDElements;
	holdDElements.reserve(d);

	// fill holdDElements with the first d elements
	// O(d)
	for (int i = 0; i < d; i++)
	{
		holdDElements.push_back(arr[i]);
	}

	// for the elements at index d and later
	// O(n - d)
	for (int i = d; i < n; i++)
	{
		// move them to the left by d
		arr[i - d] = arr[i];
	}

	// for each of the last d indices in the array put back the previously held holdDElements
	// O(d)
	for (int i = n - d; i < n; i++)
	{
		// assign the held d elements to those indices in order
		// since we need to map the 0 -> d elements in holdDElements to the 
		// we need to subtract the offset from index 0, the offset is the size of our array minus d; this offset is the base index
		// so we can place holdDElements[0] at arr[arr.size() - d], the first of the lat d indices of our array
		arr[i] = holdDElements[i - (n - d)];
	}

	return arr;
}

// JUST IN CASE YOU CAN'T USE REVERSE FUNCTION
// THIS IS THE MANUAL REVERSE
void manualReverse(std::vector<int> arr, int start, int end)
{
	while (start <= end)
	{
		// store the start value since it's about to get overwritten
		int temp = arr[start];
		// overwrite the value at start with the value at end
		arr[start] = arr[end];
		// overwrite the value at end with the held value of start
		arr[end] = temp;
		start++;
		end--;
	}
}

// optimal
// Time Complexity O(2n); O(d) + O(n-d) + O(n) = O(2n)
// Space Complexity O(1) since we're not using any extra space
std::vector<int> leftRotateArrayDPlacesOptimal(std::vector<int> arr, int d)
{
	d = d % arr.size();
	// reverse the first d elements O(d)
	std::reverse(arr.begin(), arr.begin() + d);
	// reverse from d onwards O(n-d)
	std::reverse(arr.begin() + d, arr.end());
	// reverse the entire array O(n)
	std::reverse(arr.begin(), arr.end());
	return arr;
}

int main()
{
	std::vector<int> arr = { 1, 2, 3, 4, 5, 6, 7 };
	int d = 3;
	//std::vector<int> rotatedArray = leftRotateArrayDPlaces(arr, d);
	std::vector<int> rotatedArray = leftRotateArrayDPlacesOptimal(arr, d);

	for (int i = 0; i < rotatedArray.size(); i++)
	{
		std::cout << rotatedArray[i] << " ";
	}

	return 0;
}