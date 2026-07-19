/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true

Explanation:
The element 1 occurs at the indices 0 and 3.

Example 2:
Input: nums = [1,2,3,4]
Output: false

Explanation:
All elements are distinct.

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
*/

#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        // using unordered_set since we can easily find duplicates without needing to worry about a separate frequency count like unordered_map could track
        // access and search time is O(1) amortized
        std::unordered_set<int> seen;

        // for each value in the input vector
        for (int num : nums)
        {
            // count returns 1 if the input value exists in the unordered_set, returns 0 otherwise
            // if the input value already exists during this check then the number we're currently looking at has already been seen so return true
            if (seen.count(num))
            {
                return true;
            }
            // we haven't seen the current number yet so insert it into the seen values set
            seen.insert(num);
        }
        // we didn't find any duplicates so return false
        return false;
    }
};


int main()
{
    // use the inputs LeetCode gives us
    std::vector<int> v1 = {1, 2, 3, 1};
    std::vector<int> v2 = {1, 2, 3, 4};
    std::vector<int> v3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};

    // make instance of Solution class
    Solution solution;

    // call the containsDuplicate function on our input vectors
    bool r1 = solution.containsDuplicate(v1);
    bool r2 = solution.containsDuplicate(v2);
    bool r3 = solution.containsDuplicate(v3);

    // print if those input vectors have duplicates or not
    // std::boolalpha allows the boolean output to be shown as true/false instead of 1/0
    std::cout << "v1 has duplicate? " << std::boolalpha << r1 << std::endl;
    std::cout << "v2 has duplicate? " << std::boolalpha << r2 << std::endl;
    std::cout << "v3 has duplicate? " << std::boolalpha << r3 << std::endl;

    return 0;
}
