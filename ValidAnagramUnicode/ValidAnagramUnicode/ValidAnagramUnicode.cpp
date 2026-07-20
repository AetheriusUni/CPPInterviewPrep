/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Example 1:
Input: s = "ɑanagram", t = "ɑnagaram"
Output: true

Example 2:
Input: s = "ɑrat", t = "ɑcar"
Output: false

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters AND UNICODE CHARACTERS.
*/

#include <iostream>
#include <string>
#include <unordered_map>

class Solution
{
public:
	bool isAnagram(std::string s, std::string t)
	{
		// t can only be an anagram of s if it's the same length
		if (s.size() != t.size())
		{
			return false;
		}

		// use unordered_map to store char (first) and frequency of that char (second)
		std::unordered_map<char, int> charFreq;

		// for each character in both strings
		for (int i = 0; i < s.size(); i++)
		{
			// increment the frequency when looking at s
			charFreq[s[i]]++;
			// decrement the frequency when looking at t
			charFreq[t[i]]--;
			// if t is an anagram of s the frequencies should end up being 0 due to this logic
		}

		// for each of the char, int pairs in charFreq
		for (const auto& pair : charFreq)
		{
			// if the frequency is not 0 we return false since that means there was not an equal amount of this character between the two strings
			if (pair.second != 0)
			{
				return false;
			}
		}

		// we didn't run into any issues so t is an anagram of s
		return true;
	}
};

int main()
{
	std::string s1 = "ɑanagram";
	std::string t1 = "nagaramɑ";

	std::string s2 = "ɑrat";
	std::string t2 = "ɑcar";

	Solution solution;

	std::cout << "Are " << s1 << " and " << t1 << " anagrams?\n" << std::boolalpha << solution.isAnagram(s1, t1) << std::endl;
	std::cout << "Are " << s2 << " and " << t2 << " anagrams?\n" << std::boolalpha << solution.isAnagram(s2, t2) << std::endl;

	return 0;
}

// this solution is O(n) since we go through each character of the input strings