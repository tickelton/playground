/*

# Next Greater Element II

Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.


## Example 1:

Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.


## Example 2:

Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]


## Constraints:

* 1 <= nums.length <= 10^4
* -10^9 <= nums[i] <= 10^9

*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // monotonic stack
        vector<int> ret(nums.size(), -1);

        stack<int> s;
        for (int i = nums.size() * 2 - 1; i>=0; --i) {
            while (!s.empty() && nums[s.top()] <= nums[i%nums.size()]) {
                s.pop();
            }
            ret[i%nums.size()] = s.empty() ? -1 : nums[s.top()];
            s.push(i%nums.size());
        }
        return ret;

        // brute force solution
        /*
        vector<int> ret;
        for (int k = 0; k<nums.size(); ++k) {
            int n = nums[k];
            bool found = false;
            for (int i=(k+1)%nums.size(); i != k; i = (i+1)%nums.size()) {
                if (nums[i] > nums[k]) {
                    ret.push_back(nums[i]);
                    found = true;
                    break;
                }
            }
            if (!found) { ret.push_back(-1); }
        }

        return ret;
        */
    }
};
