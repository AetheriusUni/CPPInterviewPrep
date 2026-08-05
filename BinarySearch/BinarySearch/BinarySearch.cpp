#include <iostream>
#include <iterator>

// int arr[] = given this array
// int n = the size of that array
// int target = the value we are looking for
// return index of element if found, -1 otherwise
int iterativeBinarySearch(int arr[], int n, int target)
{
	// index of lowest element to look for
	int low = 0;
	// index of highest element to look for
	int high = n - 1;
	
	// if high is lower than low, no more searching to be done
	while (low <= high)
	{
		int mid = (low + high) / 2;
		// if we found the value at mid, return the mid
		if (target == arr[mid])
		{
			return mid;
		}
		// if value we're looking for is smaller than the mid
		else if (target < arr[mid])
		{
			// make it so in the next interation we look in the range of low to 1 before mid since we have already checked mid
			high = mid - 1;
		}
		// if the value we're looking for is bigger than the mid
		else
		{
			// make it so in the next iteration we look in the range of 1 after mid to high since we have already checked mid
			low = mid + 1;
		}
	}

	return -1;
}

// int arr[] = given this array
// int n = the size of that array
// int target = the value we are looking for
// return index of element if found, -1 otherwise
int recursiveBinarySearch(int arr[], int low, int high, int target)
{
	if (low > high)
	{
		return -1;
	}

	int mid = (low + high) / 2;

	// if we found the target value, return the index of it
	if (arr[mid] == target)
	{
		return mid;
	}
	// if the target is smaller than the middle value, change high to be 1 below mid
	else if (arr[mid] > target)
	{
		return recursiveBinarySearch(arr, low, mid - 1, target);
	}
	// if the target is bigger than the middle value, change low to be 1 above mid
	else
	{
		return recursiveBinarySearch(arr, mid + 1, high, target);
	}
}

int main()
{
	int arr[] = { 3, 4, 6, 7, 9, 12, 16, 17 };
	int sizeOfArr = std::size(arr);
	int target = 6;

	//int indexOfTarget = iterativeBinarySearch(arr, sizeOfArr, target);
	int indexOfTarget = recursiveBinarySearch(arr, 0, sizeOfArr - 1, target);
	
	std::cout << "Index of " << target << " in array: " << indexOfTarget << std::endl;

	return 0;
}