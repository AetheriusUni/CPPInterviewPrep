// get second largest element in array, assume array has at least 2 values and all values are non-negative integers
// also get second smallest element

#include <iostream>
#include <iterator>

// O(n) time complexity since we go through each value in arr once
int getSecondLargest(int arr[], int sizeOfArray)
{
	int largest = arr[0];
	int secondLargest = -1;

	for (int i = 1; i < sizeOfArray; i++)
	{
		// if an element becomes larger than largest
		if (arr[i] > largest)
		{
			// secondLargest becomes the previous largest
			secondLargest = largest;
			// largest is now that larger element
			largest = arr[i];
		}
		// if an element isn't bigger than largest, but is bigger than secondLargest
		else if (arr[i] < largest && arr[i] > secondLargest)
		{
			// secondLargest gets that element's value
			secondLargest = arr[i];
		}
	}

	return secondLargest;
}

// O(n) time complexity since we go through each value in arr once
int getSecondSmallest(int arr[], int sizeOfArray)
{
	int smallest = arr[0];
	int secondSmallest = INT_MAX;

	for (int i = 1; i < sizeOfArray; i++)
	{
		// if an element becomes smaller than smallest
		if (arr[i] < smallest)
		{
			// secondSmallest becomes the previous smallest
			secondSmallest = smallest;
			// smallest is now that smaller element
			smallest = arr[i];
		}
		// if an element isn't smaller than smallest, but is smaller than secondSmallest
		else if (arr[i] > smallest && arr[i] < secondSmallest)
		{
			// secondSmallest gets that element's value
			secondSmallest = arr[i];
		}
	}

	return secondSmallest;
}

int main()
{
	int arr[] = { 1, 2, 4, 7, 7, 5 };
	int sizeOfArray = std::size(arr);
	int secondLargest = getSecondLargest(arr, sizeOfArray);
	int secondSmallest = getSecondSmallest(arr, sizeOfArray);

	std::cout << "Second Largest Value: " << secondLargest << std::endl;
	std::cout << "Second Smallest Value: " << secondSmallest << std::endl;

	return 0;
}