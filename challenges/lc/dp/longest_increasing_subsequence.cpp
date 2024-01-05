/*

# Longest Increasing Subsequence

Given an integer array nums, return the length of the longest strictly increasing subsequence.


## Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.


## Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4


## Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1


## Constraints:

* 1 <= nums.length <= 2500
* -10^4 <= nums[i] <= 10^4

*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);

        int ret = 1;
        for (int i=nums.size()-2; i>=0; --i) {
            int max_seq = 1;
            for (int j=i+1; j<nums.size(); ++j) {
                int seq = 1;
                if (nums[i] < nums[j]) {
                    seq = dp[j] + 1;
                }
                if (seq > max_seq) {
                    max_seq = seq;
                }
            }
            dp[i] = max_seq;
            if (max_seq > ret) {
                ret = max_seq;
            };
        }

        return ret;
    }
};
