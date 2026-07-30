#include <iostream>
#include <vector>

std::vector<int> leftRotateArrayOnce (std::vector<int> &arr, int n)
{
	int firstElement = arr[0];

	// move all the other elements that aren't the first element one to the left
	for (int i = 1; i < arr.size(); i++)
	{
		arr[i - 1] = arr[i];
	}

	// move the firstElement to the last index
	arr[arr.size() - 1] = firstElement;

	return arr;
}

int main()
{
	std::vector<int> arr = { 1, 2, 3, 4, 5 };
	std::vector<int> rotatedArray = leftRotateArrayOnce(arr, arr.size());

	for (int i = 0; i < rotatedArray.size(); i++)
	{
		std::cout << rotatedArray[i] << " ";
	}

	return 0;
}