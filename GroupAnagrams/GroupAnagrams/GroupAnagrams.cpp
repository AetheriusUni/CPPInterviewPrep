/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:

There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.

Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]]

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution
{
	public:
		std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs)
		{
			// hash map to hold the sorted version of the unique strings
			std::unordered_map<std::string, std::vector<std::string>> anagramMap;

			// go through every string in strs
			for (const std::string& str : strs) 
			{
				std::string sortedStr = str;
				// sort string so it's obvious what is an anagram of what
				std::sort(sortedStr.begin(), sortedStr.end());

				// push the original not sorted string into the corresponding group (grouped by sorted string)
				// if the group does not exist yet this will initialize that group
				anagramMap[sortedStr].push_back(str);
			}

			// Collect all grouped vectors from the hash map into the final result
			std::vector<std::vector<std::string>> result;
			result.reserve(anagramMap.size()); // Optimize memory allocation to be the size of the anagramMap which has every element in it

			// anagramMap contains pair<string, vector<string>>
			// accessing second is the vector of strings we want to return
			for (auto& pair : anagramMap) 
			{
				// Use move to avoid copying strings
				// using result.push_back(pair.second); is the less optimal, but likely typical way to do this in an interview setting
				result.push_back(std::move(pair.second)); 
			}

			return result;
		}
};

void printResults(std::vector<std::vector<std::string>> rValue)
{
	// for each of the groups in rValue
	for (int i = 0; i < rValue.size(); i++)
	{
		// each group starts with a starting bracket
		std::cout << "[";

		// for each of the values in the vector at index i
		// output them
		for (int j = 0; j < rValue[i].size(); j++)
		{
			std::cout << "\"" << rValue[i][j] << "\"";
			if (j != rValue[i].size() - 1)
			{
				std::cout << ", ";
			}
		}
		// and add an ending bracket when done
		std::cout << "]";
		// if there's more vectors to go add a comma with a space
		if (i != rValue.size() - 1)
		{
			std::cout << ", ";
		}
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<std::string> sVector1 = {"eat","tea","tan","ate","nat","bat"};
	std::vector<std::string> sVector2 = {""};
	std::vector<std::string> sVector3 = {"a"};

	Solution solution;

	std::vector<std::vector<std::string>> r1 = solution.groupAnagrams(sVector1);
	std::vector<std::vector<std::string>> r2 = solution.groupAnagrams(sVector2);
	std::vector<std::vector<std::string>> r3 = solution.groupAnagrams(sVector3);

	printResults(r1);
	printResults(r2);
	printResults(r3);

	return 0;
}

/*
This approach is amortized O(n * k log k) time where n is the number of strings and k is the maximum length of a string
The n comes from having to iterate through n items
Sorting the strings takes amortized O(k log k) time

Space complexity is O(n*k) since we have to store the strings inside the hash map and final tracking array
*/


/*

This version of the solution is the intuitive one that solves the problem with no optimizations
This is O(n^2 * k log k) where n is the number of input strings in the strs and k is the length of a string
Sorting the strings takes O(k log k)
searching vHolder takes O( n * k )

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

class Solution
{
	public:
		std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs)
		{
			// naive approach
			std::vector<std::string> vHolder = {};
			std::vector<std::string> strsCopy = strs;
			std::vector<std::vector<std::string>> rVal;

			// for each of the strings in strsCopy
			for (int i = 0; i < strsCopy.size(); i++)
			{
				// sort each string so the anagrams will be immediately obvious
				std::sort(strsCopy[i].begin(), strsCopy[i].end());

				auto it = std::find(vHolder.begin(), vHolder.end(), strsCopy[i]);
				// if we find that this sorted string is already in vHolder
				if (it != vHolder.end())
				{
					// get its index in vHolder and push_back the original non-sorted version of the string to rVal at the index
					const uint64_t index = std::distance(vHolder.begin(), it);
					rVal[index].push_back(strs[i]);
				}
				else
				{
					// keep track of which sorted strings we've seen
					vHolder.push_back(strsCopy[i]);
					// creates a new inner vector group inside rVal with the unsorted string
					rVal.push_back({ strs[i] });
				}
			}
			return rVal;
		}
};
*/