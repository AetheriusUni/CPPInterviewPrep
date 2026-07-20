/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. 
Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.


Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
*/

#include <iostream>
#include <string>
#include <cctype>

class Solution
{
public:
	bool isPalindrome(std::string s)
	{
		// using a left and right pointer to be able to check if the string is a valid palindrome from both sides
		// which allows us to return false early if there's a mismatch between the pointed at characters
		int left = 0;
		int right = s.size() - 1;

		while (left < right) {
			// Skip non-alphanumeric characters from the left
			while (left < right && !std::isalnum(s[left])) {
				left++;
			}
			// Skip non-alphanumeric characters from the right
			while (left < right && !std::isalnum(s[right])) {
				right--;
			}

			// Compare the currently pointed at characters after converting them to lowercase
			// if there's a mismatch return false since any mismatch means we're not looking at a valid palindrome
			if (std::tolower(s[left]) != std::tolower(s[right])) {
				return false;
			}

			// Move both pointers closer to the center
			left++;
			right--;
		}

		return true;
	}
};



int main()
{
	std::string s1 = "A man, a plan, a canal: Panama";
	std::string s2 = "race a car";
	std::string s3 = " ";

	Solution solution;

	std::cout << "Input: " << s1 << std::endl << "Is palindrome? " << std::boolalpha << solution.isPalindrome(s1) << std::endl;
	std::cout << "Input: " << s2 << std::endl << "Is palindrome? " << std::boolalpha << solution.isPalindrome(s2) << std::endl;
	std::cout << "Input: " << s3 << std::endl << "Is palindrome? " << std::boolalpha << solution.isPalindrome(s3) << std::endl;

	return 0;
}


/*
Less optimal solution, but more intuitive
bool isPalindrome(std::string s)
{
	// remove all non-alphanumeric characters
	std::erase_if( s, [](unsigned char c)
	{
		return !std::isalnum(c);
	});
	// make all remaining letters lowercase
	for (char& c : s)
	{
		c = std::tolower(static_cast<unsigned char>(c));
	}
	// go through each character from index i = 0 to s.size()/2 and each character from s.size() - 1 to s.size/2
	for (int i = 0; i < s.size() / 2; i++)
	{
		if (s[i] != s[s.size() - 1 - i])
		{
			return false;
		}
	}
	return true;
}
*/