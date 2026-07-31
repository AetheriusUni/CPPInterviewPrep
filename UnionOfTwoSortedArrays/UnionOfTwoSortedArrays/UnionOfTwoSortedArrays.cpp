// given two sorted arrays, return the union of them

#include <iostream>
#include <set>
#include <vector>

// brute force
// Time Complexity O(n1 log n + n2 log n) + O(n1 + n2)
// Space Complexity O(n1 + n2) + O(n1 + n2); space to solve problem (uniqueVals) + space to return answer (rArray)
std::vector<int> unionArrFunc(std::vector<int>& arr1, std::vector<int>& arr2)
{
	std::set<int> uniqueVals;
	// put all the values of both arrays into a set
	// O(n1 log n) where n1 is the size of arr1
	// O(log n) average and worst case insert for SET
	// O(1) amortized insert for UNORDERED_SET, O(n) worst case if there are many collisions
	for (int i = 0; i < arr1.size(); i++)
	{
		uniqueVals.insert(arr1[i]);
	}

	// O(n2 log n) where n2 is the size of arr2
	for (int i = 0; i < arr2.size(); i++)
	{
		uniqueVals.insert(arr2[i]);
	}

	// get all the values from the set and add them to a new array
	std::vector<int> rArray;

	// technically could use const int& val, but this is much less maintanable in a real coding environment
	// O(n1 + n2)
	for (const auto& val : uniqueVals)
	{
		rArray.push_back(val);
	}

	/*
	in the case we had to return an actual array
	int rArray[uniqueVals.size()];
	int i = 0;

	for (auto val : uniqueVals)
	{
		rArray[i++] = val;
	}
	*/

	return rArray;
}

// optimal
// Time Complexity O(n1 + n2)
// Space Complexity O(n1 + n2) for returning the rArray, not for solving since technically the values could be printed instead of stored and we wouldn't need any space
std::vector<int> unionArrOptimal(std::vector<int>& arr1, std::vector<int>& arr2)
{
	// index in arr1
	int i = 0;
	// index in arr2
	int j = 0;
	// return array
	std::vector<int> rArray;
	int n1 = arr1.size();
	int n2 = arr2.size();

	while (i < n1 && j < n2)
	{
		// primarily go through arr1
		if (arr1[i] <= arr2[j])
		{
			// if rArray is empty or the last value in rArray != current arr1 value
			if (rArray.size() == 0 || (rArray.back() != arr1[i]))
			{
				// add arr1[i] to the rArray
				rArray.push_back(arr1[i]);
			}
			// then look at the next value
			i++;
		}
		// in the case arr2[j] < arr1[i] and arr2[j] != last in rArray
		else 
		{
			// if rArray is empty or the last value in rArray != current arr2 value
			if (rArray.size() == 0 || (rArray.back() != arr2[j]))
			{
				// add arr2[j] to the rArray
				rArray.push_back(arr2[j]);
			}
			// then look at the next value
			j++;
		}
	}

	// if there are still elements in arr1
	while (i < n1)
	{
		// if rArray is empty or the last value in rArray != current arr1 value
		if (rArray.size() == 0 || (rArray.back() != arr1[i]))
		{
			// add arr1[i] to the rArray
			rArray.push_back(arr1[i]);
		}
		// then look at the next value
		i++;
	}

	// if there are still elements in arr2
	while (j < n2)
	{
		// if rArray is empty or the last value in rArray != current arr2 value
		if (rArray.size() == 0 || (rArray.back() != arr2[j]))
		{
			// add arr2[j] to the rArray
			rArray.push_back(arr2[j]);
		}
		// then look at the next value
		j++;
	}

	return rArray;
}


int main()
{
	std::vector<int> arr1 = { 1, 1, 2, 3, 4, 5 };
	std::vector<int> arr2 = { 2, 3, 4, 4, 5, 6 };
	//std::vector<int> unionArr = unionArrFunc(arr1, arr2);
	std::vector<int> unionArr = unionArrOptimal(arr1, arr2);

	// should be 1 2 3 4 5 6
	for (int i = 0; i < unionArr.size(); i++)
	{
		std::cout << unionArr[i] << " ";
	}

	return 0;
}