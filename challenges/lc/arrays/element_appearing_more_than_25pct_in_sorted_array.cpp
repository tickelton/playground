/*

# Element Appearing More Than 25% In Sorted Array

Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time, return that integer.


## Example 1:

Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6


## Example 2:

Input: arr = [1,1]
Output: 1


## Constraints:

* 1 <= arr.length <= 10^4
* 0 <= arr[i] <= 10^5

*/

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int cur = arr[0];
        int cur_count = 0;

        for (auto i: arr) {
            if (i != cur) {
                if (cur_count > arr.size()/4) {
                    return cur;
                }
                cur = i;
                cur_count = 1;
            } else {
                ++cur_count;
            }
        }

        return cur;
    }
};
