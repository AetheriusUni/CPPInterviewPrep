// TwoSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]


Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.


Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
*/

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum( std::vector<int>& nums, int target ) 
    {
        // use unordered_map to track numbers we've already seen 
        // Key = the number we're looking at
        // Value = the index of that number
        // this hash map is O(1) for insertions and lookups
        std::unordered_map<int, int> numMap;

        // go through each value in the input vector
        // i is the location of our current value in nums
        for (int i = 0; i < nums.size(); ++i) 
        {
            // gets the value that, when added to the nums[1], gets us the sum that equals target
            int complement = target - nums[i];

            // if we're able to find the complement in the numMap return a vector containing the location of the compliment and i 
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }

            // if we can't find the compliment, add to numMap the current number with the index i
            // Key = nums[i]
            // Val = i
            numMap[nums[i]] = i;
        }
        // we were unable to find a number with a compliment to give us a two sum in the array so return an empty vector
        return {};
    }
};

int main() 
{
    // define the input data
    std::vector<int> nums = { 2, 7, 11, 15 };
    int target = 9;

    // create an instance of the Solution class
    Solution solution;

    // call the twoSum function and store the result
    std::vector<int> result = solution.twoSum(nums, target);

    // print the output if result is not empty, print that no solution was found otherwise
    if ( !result.empty() ) {
        std::cout << "Indices: [" << result[0] << ", " << result[1] << "]" << std::endl;
    }
    else {
        std::cout << "No two sum solution found." << std::endl;
    }

    return 0;
}

// this solution is O(n) time complexity since the for loop goes through each element of the input vector in the worst case if a solution isn't found sooner
// this solution is O(n) space complexity since the numMap can possibly store up to n-1 elements in it if the two numbers are the last two elements

/*
if the input vector is sorted the two pointer approach can be used where one pointer points to the starting index (left) and the other points towards the end index (right)
if the sum of the left and right is greater than the target, move the right pointer -1
if the sum of the left and right is less than the target, move the left pointer +1
if the sum matches the target, return a vector conatining {left, right}
the two pointer approach is the same time complexity as the original solution O(n), but does not use any extra memory so the space complexity is O(1)
*/ 