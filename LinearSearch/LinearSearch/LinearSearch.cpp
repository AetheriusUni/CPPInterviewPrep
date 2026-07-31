// return the index of the target number in the array, return -1 if not found

#include <iostream>
#include <iterator>

// Time Complexity O(n)
// Space Complexity O(1)
int linearSearch(int arr[], int n, int target)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == target)
		{
			return i;
		}
	}

	return -1;
}

int main()
{
	int arr[] = { 6, 7, 8, 4, 1};
	int n = std::size(arr);
	int target = 4;
	int searchResult = linearSearch(arr, n, target);

	return 0;
}