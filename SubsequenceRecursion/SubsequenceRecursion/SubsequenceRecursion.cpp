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