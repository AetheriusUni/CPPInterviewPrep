#include <iostream>
#include <vector>

void printSubsequences(int index, std::vector<int> &subsequence, int arr[], int sizeOfArray)
{
	// base case: if index is greater than or equal to the size of the array we have already processed the last value in the array
	// technically it should be impossible for index > sizeOfArray
	if ( index >= sizeOfArray )
	{
		// print the subsequence
		for (int i = 0; i < subsequence.size(); i++)
		{
			std::cout << subsequence[i];
			// only add a space after if we're not the last element
			if (i < subsequence.size() - 1)
			{
				std::cout << " ";
			}
		}
		// if there's nothing in subsequence print empty vector
		if (subsequence.size() == 0)
		{
			std::cout << "{}";
		}
		std::cout << std::endl;
		return;
	}

	// at this point it's confirmed we haven't processed the last value in the array 
	// pick/take/add value of arr at current index to the subsequence
	subsequence.push_back(arr[index]);

	// pick the value at the next index
	printSubsequences(index + 1, subsequence, arr, sizeOfArray);

	// don't pick/take/add the value of arr at the current index to the subsequence
	subsequence.pop_back();

	// pick the value at the next index
	printSubsequences(index + 1, subsequence, arr, sizeOfArray);
}


int main()
{
	int arr[] = { 3, 1, 2 };
	int n = std::size(arr);
	std::vector<int> subsequence;
	printSubsequences(0, subsequence, arr, n);

	return 0;
}

// Time Complexity: O(2^n * n)
// 2^n because for each index one can take or not take, 2 options
// n because we can print at most n characters per sequence
// Space Complexity: O(n)
// at most the number of recusive calls being held in stack memory is n

/*
#include <array>

// Must use & here to avoid copying the fixed-size array
void printModernArray(const std::array<int, 5>& arr) 
{
	std::cout << arr.size(); // It remembers its size!
}

^ instead of using int arr[] like in the not commented code above can use std::array<int, 3> arr = { 3, 1, 2 };
then pass in to printSubsequences std::array<int, 3>& arr
we can use the .size() with the std::array
*/

