#include <iostream>
#include <stack>
#include <vector>

// Time Complexity O(n)
// Space Complexity O(n)
bool isBalancedParentheses(std::string inputString)
{
	std::stack<char> st;

	for (char c : inputString)
	{
		// if we're an opening parenthesis (c) push to stack
		if (c == '(' || c == '{' || c == '[')
		{
			st.push(c);
		}
		// if we're a closing parenthesis (c)
		else
		{
			// if the stack is empty at this time then there is no matching open parenthesis so we return false
			if (st.empty())
			{
				return false;
			}

			// store the top and pop it
			char poppedChar = st.top();
			st.pop();

			// if the popped char doesn't match the closed parenthesis that c is
			if (!((poppedChar == '(' && c == ')') || (poppedChar == '{' && c == '}') || (poppedChar == '[' && c == ']')))
			{
				return false;
			}
		}
	}
	// if stack is empty we are returning true
	// if stack is not empty then we have extra opening parentheses so return false
	return st.empty();
}

int main()
{
	std::vector<std::string> inputStrings;
	inputStrings.push_back("(()");
	inputStrings.push_back("))");
	inputStrings.push_back("((");
	inputStrings.push_back("(({}[]))");

	for (int i = 0; i < inputStrings.size(); i++)
	{
		std::cout << "String: " << inputStrings[i] << std::endl;
		std::cout << "Is Balanced? " << std::boolalpha << isBalancedParentheses(inputStrings[i]) << std::endl;
	}

	return 0;
}