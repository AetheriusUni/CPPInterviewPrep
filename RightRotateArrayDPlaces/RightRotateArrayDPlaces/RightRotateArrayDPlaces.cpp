#include <iostream>
#include <vector>
#include <algorithm>

// brute force
// Time Complexity = O(n + d)
// Space Complexity = O(d) since we store d elements in dHolder
std::vector<int> rightRotateDPlaces(std::vector<int>& arr, int d)
{
	// store size of array since we'll use it a lot
	int n = arr.size();

	// make d fit within the bounds of the size of array since the rotation of size n results in no change
	d = d % n;

	// holder of the d rightmost elements
	std::vector<int> dHolder;

	// O(d)
	// store the rightmost d elements
	for (int i = n - d; i < n; i++)
	{
		dHolder.push_back(arr[i]);
	}

	// move the elements that aren't in dHolder to the right d places
	// need to start at the back since starting at the front can result in an overwritten value
	
	// example case with our 1 2 3 4 5 6 7 array and d = 3
	// 1 2 3 1 5 6 7 -- i = 0
	// 1 2 3 1 2 6 7 -- i = 1
	// 1 2 3 1 2 3 7 -- i = 2
	// 1 2 3 1 2 3 1 -- i = 3; the 1 at the end is supposed to be 4, but 4 was overwritten in a prior iteration when i=0
	
	// correct behavior by starting at the back
	// 1 2 3 4 5 6 4 -- i = 3
	// 1 2 3 4 5 3 4 -- i = 2
	// 1 2 3 4 2 3 4 -- i = 1
	// 1 2 3 1 2 3 4 -- i = 0

	// O(n - d)
	for (int i = d; i >= 0; i--)
	{
		// n-d-1 == (index where the right shifted elements start to move to)
		// i == (which slot among 
		arr[n - d - 1 + i] = arr[i];
	}

	// O(d)
	// place the dHolder elements in the first d indices
	for (int i = 0; i < d; i++)
	{
		arr[i] = dHolder[i];
	}

	return arr;
}

// optimal
// reverse is start INCLUSIVE and end EXCLUSIVE
// Time Complexity O(2n) since we have O(n) + O(d) + O(n - d)
// Space Complexity O(1) since no extra space was used
std::vector<int> rightRotateDPlacesOptimal(std::vector<int>& arr, int d)
{
	int n = arr.size();
	d = d % n;
	// starting with 
	// 1 2 3 4 5 6 7
	
	// reverse all O(n)
	// 7 6 5 4 3 2 1
	std::reverse(arr.begin(), arr.end());

	// reverse first d elements O(d)
	// 5 6 7 4 3 2 1
	std::reverse(arr.begin(), arr.begin() + d);

	// reverse last n-d elements O(n - d)
	// 5 6 7 1 2 3 4
	std::reverse(arr.begin() + d, arr.end());
	return arr;
}

int main()
{
	std::vector<int> arr = { 1, 2, 3, 4, 5, 6, 7 };
	int d = 3;
	//std::vector<int> rotatedArray = rightRotateDPlaces(arr, d);
	std::vector<int> rotatedArray = rightRotateDPlacesOptimal(arr, d);

	// the result in this case should be 5 6 7 1 2 3 4
	for (int i = 0; i < arr.size(); i++)
	{
		std::cout << rotatedArray[i] << " ";
	}

	return 0;
}