/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.


Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
*/

#include <iostream>
#include <string>
//#include <algorithm>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) 
    {
        // if the strings aren't the same length then t can't be an anagram of s
        // s.size() is the same as s.length()
        if (s.length() != t.length())
        {
            return false;
        }

        // there are 26 letters in the alphabet
        // since the inputs are all lowercase letters we only care about the 26 lowercase letters
        int count[26] = { 0 };

        // for each index i in the string s (or t since they're the same length)
        for (int i = 0; i < s.length(); i++)
        {
            // increment the value stored at the index corresponding to the character we're looking at
            count[s[i] - 'a']++;
            // decrement the value stored at the index corresponding to the character we're looking at
            count[t[i] - 'a']--;
            // by incrementing instances of the characters in s and decrementing instances of the characters in t
            // all the values in count should be 0 if t is an anagram of s
        }

        // for each of the indices in count
        for (int i = 0; i < std::size(count); i++)
        {
            // if the value at an index is not equal to 0
            if (count[i] != 0)
            {
                // t is not an anagram of s
                return false;
            }
        }
        
        // we didn't run into any issue so t must be an anagram of s
        return true;
        // this solution is O(n) since we go through each of the n characters of the input strings s and t

        
        // START SIMPLE SOLUTION
        // the simple solution would be to sort the strings then compare them, but this is not optimal since doing sort is O(n log n) which is slower than the O(n) approach above
        // this solution requires #include <algorithm> to use sort
        // sort the strings so we can do an equality comparison with all the letters in the right place
        //std::sort(s.begin(), s.end());
        //std::sort(t.begin(), t.end());

        // return if s is equivalent to t or not
        //return s == t;
        // END SIMPLE SOLUTION
    }
};

int main()
{
    std::string s1 = "anagram";
    std::string t1 = "nagaram";

    std::string s2 = "rat";
    std::string t2 = "car";

    Solution solution;

    std::cout << "Are " << s1 << " and " << t1 << " anagrams?\n" << std::boolalpha << solution.isAnagram(s1, t1) << std::endl;
    std::cout << "Are " << s2 << " and " << t2 << " anagrams?\n" << std::boolalpha << solution.isAnagram(s2, t2) << std::endl;

    return 0;
}

/*
In order to address the follow up question of how to handle strings with unicode characters we'd need to use a unordered_map<char, int> 
which we could use to count the frequency of each character.
The solution is basically the same otherwise, the main difference is to not use the int count[26] and use unordered_map<char, int> charCount instead.
*/