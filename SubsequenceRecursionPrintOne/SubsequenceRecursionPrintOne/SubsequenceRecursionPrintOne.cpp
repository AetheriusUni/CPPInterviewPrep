// print one subsequence that satisfies the condition "the sum the numbers in the subsequence is equal to the targetSum"
// after this print stop the remaining recursion

#include <iostream>
#include <vector>

bool printOneSubsequence(int index, std::vector<int> subsequence, int currentSum, int targetSum, int arr[], int arrSize)
{
	// base case
	if (index == arrSize)
	{
		if (currentSum == targetSum)
		{
			for (auto it : subsequence)
			{
				std::cout << it << " ";
			}
			std::cout << std::endl;
			return true;
		}
		return false;
	}

	// choose to add arr[index] to sequence
	subsequence.push_back(arr[index]);
	// add arr[index] to the currentSum
	currentSum += arr[index];
	// if adding the next value arr[index + 1] with adding arr[index] results in the currentSum == targetSum return true
	if (printOneSubsequence(index + 1, subsequence, currentSum, targetSum, arr, arrSize) == true)
	{
		return true;
	}

	// choose to not add arr[index] to sequence
	subsequence.pop_back();
	// we need to subtract the arr[index] from currentSum since it shouldn't be included here
	currentSum -= arr[index];
	// if adding the next value arr[index + 1] without adding arr[index] results in the currentSum == targetSum return true
	if (printOneSubsequence(index + 1, subsequence, currentSum, targetSum, arr, arrSize) == true)
	{
		return true;
	}

	// after picking or not picking the current arr[index] we were unable to find a currentSum == targetSum
	return false;
}

int main()
{
	int arr[] = {1, 2, 1};
	int n = std::size(arr);
	std::vector<int> subsequence;
	int targetSum = 2;
	bool result = printOneSubsequence( 0, subsequence, 0, targetSum, arr, n );
	return 0;
}