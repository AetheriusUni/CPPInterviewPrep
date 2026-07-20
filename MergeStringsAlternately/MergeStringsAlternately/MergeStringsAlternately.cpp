/*
You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r

Example 2:

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b
word2:    p   q   r   s
merged: a p b q   r   s

Example 3:

Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q
merged: a p b q c   d


Constraints:

1 <= word1.length, word2.length <= 100
word1 and word2 consist of lowercase English letters.
*/

#include <iostream>
#include <string>

class Solution {
public:
    std::string mergeAlternately(std::string word1, std::string word2)
    {
        std::string returnVal = "";
        // reserve the space needed for all the characters in both words combined
        returnVal.reserve(word1.size() + word2.size());

        int i = 0;

        // until we've gone through all the characters in both words
        while (i < word1.size() || i < word2.size())
        {
            // push to the end of the return string, prioritizing word1 first
            if (i < word1.size())
            {
                returnVal.push_back(word1[i]);
            }

            if (i < word2.size())
            {
                returnVal.push_back(word2[i]);
            }

            i++;
        }

        return returnVal;
    }
};

int main()
{
    std::string word1a = "abc";
    std::string word2a = "pqr";

    std::string word1b = "ab";
    std::string word2b = "pqrs";

    std::string word1c = "abcd";
    std::string word2c = "pq";

    Solution solution;

    std::cout << word1a << " and " << word2a << " merged is: " << solution.mergeAlternately(word1a, word2a) << std::endl;
    std::cout << word1b << " and " << word2b << " merged is: " << solution.mergeAlternately(word1b, word2b) << std::endl;
    std::cout << word1c << " and " << word2c << " merged is: " << solution.mergeAlternately(word1c, word2c) << std::endl;
}

// this is O(n) complexity since we go through each character in the input strings