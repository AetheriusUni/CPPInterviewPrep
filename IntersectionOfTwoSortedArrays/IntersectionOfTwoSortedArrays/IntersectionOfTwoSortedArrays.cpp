// intersection of two sorted arrays
// intersection means "what do the two arrays have in common"

#include <iostream>
#include <vector>

// brute force
// Time Complexity O(n1 * n2)
// Space Complexity O(n2) if we choose arr2 for wasAdded, ideally if we knew which array was smaller to being with we could just always choose that one to save a bit more space
std::vector<int> intersectionArray(const std::vector<int>& arr1, const std::vector<int>& arr2)
{
	std::vector<int> rArray;
	int n1 = arr1.size();
	int n2 = arr2.size();
	std::vector<int> wasAdded(n2);

	// for each value in arr1
	for (int i = 0; i < n1; i++)
	{
		// check if it exists in arr2
		for (int j = 0; j < n2; j++)
		{
			// if there's a common value between arr1 and arr2 + that value wasn't previously added to rArray
			if ((arr1[i] == arr2[j]) && (wasAdded[j]==0))
			{
				rArray.push_back(arr1[i]);
				wasAdded[j] = 1;
				break;
			}
			// if arr2's value is greater than arr1's value at this point, the rest of the arr2 values will also be greater than arr1's value AKA not equal so we break
			if (arr2[j] > arr1[i])
			{
				break;
			}
		}
	}
	
	return rArray;
}

// optimal
// Time Complexity O(n1+n2)
// Space Complexity O(1) since the only space used was to store the output
std::vector<int> intersectionArrayOptimal(const std::vector<int>& arr1, const std::vector<int>& arr2)
{
	std::vector<int> rArray;
	int n1 = arr1.size();
	int n2 = arr2.size();

	// arr1 index
	int i = 0;
	// arr2 index
	int j = 0;

	while (i < n1 && j < n2)
	{
		if (arr1[i] == arr2[j])
		{
			rArray.push_back(arr1[i]);
			i++;
			j++;
		}
		else if (arr1[i] > arr2[j])
		{
			j++;
		}
		else if (arr2[j] > arr1[i])
		{
			i++;
		}
	}

	return rArray;
}

int main()
{
	std::vector<int> arr1 = { 1, 2, 2, 3, 3, 4, 5, 6 };
	std::vector<int> arr2 = { 2, 3, 3, 5, 6, 6, 7 };
	//std::vector<int> iArr = intersectionArray(arr1, arr2);
	std::vector<int> iArr = intersectionArrayOptimal(arr1, arr2);

	// should be 2 3 3 5 6
	for (int i = 0; i < iArr.size(); i++)
	{
		std::cout << iArr[i] << " ";
	}

	return 0;
}