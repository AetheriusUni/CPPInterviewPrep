/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]

Example 3:
Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2
Output: [1,2]

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.


Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
	std::vector<int> topKFrequent(std::vector<int>& nums, int k)
	{
		int numsSize = nums.size();
		std::vector<int> rVal;
		// set reserved space to k since we only need to add k items to rVal
		rVal.reserve(k);

		// since we want keys with values representing frequency unordered_map is efficient amortized O(1) insert, find
		std::unordered_map<int, int> numFreq;

		// store the frequencies of each number
		for (int num : nums)
		{
			numFreq[num]++;
		}

		// make buckets with frequency as keys and the values contain all the numbers with that frequency
		// frequencies are 1 indexed so add 1 to numFreqSize as the size of the buckets, so buckets[0] is effectively not used
		// this way we have a frequency sorting
		std::vector<std::vector<int>> buckets(numsSize + 1);
		for (auto& [num, freq] : numFreq)
		{
			buckets[freq].push_back(num);
		}

		// starting at the largest frequency working backwards
		for (int i = numsSize; i >= 0; --i)
		{
			// push the values in that bucket
			for (int num : buckets[i]) 
			{
				rVal.push_back(num);
				// and if we hit our quota k return the rVal at this time
				if (rVal.size() == k) 
				{
					return rVal;
				}
			}
		}
		return rVal;
	}
};

void printResults(std::vector<int> v)
{
	std::cout << "[";
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i];
		if (i < v.size() - 1)
		{
			std::cout << ", ";
		}
		else
		{
			std::cout << "]\n";
		}
	}
}

int main()
{
	std::vector<int> n1 = { 1,1,1,2,2,3 };
	int k1 = 2;
	
	std::vector<int> n2 = { 1 };
	int k2 = 1;
	
	std::vector<int> n3 = { 1,2,1,2,1,2,3,1,3,2 };
	int k3 = 2;
	
	Solution solution;

	printResults(solution.topKFrequent(n1, k1));
	printResults(solution.topKFrequent(n2, k2));
	printResults(solution.topKFrequent(n3, k3));

	return 0;
}

// this is O(n) since we go through each of the elements once and then iterate k times to get our return value
// in the worst case k is the same as n, but that's just 2n so the complexity is still linear O(n)