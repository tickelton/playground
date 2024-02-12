/*

# Majority Element

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.


## Example 1:

Input: nums = [3,2,3]
Output: 3


## Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2


## Constraints:

* n == nums.length
* 1 <= n <= 5 * 10^4
* -10^9 <= nums[i] <= 10^9

*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto n: nums) {
            if (m.contains(n)) {
                m[n]++;
            } else {
                m[n] = 1;
            }
        }

        for (auto [k, v]: m) {
            if (v > nums.size()/2) {
                return k;
            }
        }

        return -1;
    }
};
