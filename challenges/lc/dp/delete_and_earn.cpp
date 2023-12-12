/*

# Delete and Earn

You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:

* Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.

Return the maximum number of points you can earn by applying the above operation some number of times.


## Example 1:

Input: nums = [3,4,2]
Output: 6
Explanation: You can perform the following operations:
- Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
- Delete 2 to earn 2 points. nums = [].
You earn a total of 6 points.


## Example 2:

Input: nums = [2,2,3,3,3,4]
Output: 9
Explanation: You can perform the following operations:
- Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums = [3,3].
- Delete a 3 again to earn 3 points. nums = [3].
- Delete a 3 once more to earn 3 points. nums = [].
You earn a total of 9 points.


## Constraints:

* 1 <= nums.length <= 2 * 10^4
* 1 <= nums[i] <= 10^4

*/

class Solution {
public:
/*
    // recursion + tabulation; static allocation
    array<int, 10000> dp;
    // [0,2,3,4]
    // [0,4,9,4]
    // [0,2,0,4,5,6,7]
    int max_idx;
    int deleteAndEarnOff(array<int, 10000>& sums, int offset) {
        //if (offset >= sums.size()) {
        if (offset > max_idx) {
            return 0;
        }
        if (offset == sums.size() -1 ) {
            return sums[offset];
        }
        if (dp[offset] == -1) {
            dp[offset] = max(
                sums[offset] + deleteAndEarnOff(sums, offset+2),
                sums[offset+1] + deleteAndEarnOff(sums, offset+3)
            );
        }

        return dp[offset];
    }
    int deleteAndEarn(vector<int>& nums) {
        array<int, 10000> sums;
        sort(nums.begin(), nums.end());
        max_idx = nums[nums.size()-1]-1;

        for (int i=0; i<10000; ++i) {
            sums[i] = 0;
            dp[i] = -1;
        }

        int cur = nums[0];
        int cur_total = 0;
        for (auto i: nums) {
            if (i == cur) {
                cur_total += i;
            } else {
                sums[cur-1] = cur_total;
                cur_total = i;
                cur = i;
            }
        }
        sums[cur-1] = cur_total;

        return max(
            sums[0] + deleteAndEarnOff(sums, 2),
            sums[1] + deleteAndEarnOff(sums, 3)
        );
    }

    // recursion + tabulation; dynamic allocation
    vector<int> dp;
    vector<int> sums;
    int max_idx;
    int deleteAndEarnOff(int offset) {
        if (offset > max_idx) {
            return 0;
        }
        if (offset == sums.size() -1 ) {
            return sums[offset];
        }
        if (dp[offset] == -1) {
            dp[offset] = max(
                sums[offset] + deleteAndEarnOff(offset+2),
                sums[offset+1] + deleteAndEarnOff(offset+3)
            );
        }

        return dp[offset];
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        max_idx = nums[nums.size()-1]-1;

        for (int i=0; i<=max_idx; ++i) {
            sums.push_back(0);
            dp.push_back(-1);
        }

        int cur = nums[0];
        int cur_total = 0;
        for (auto i: nums) {
            if (i == cur) {
                cur_total += i;
            } else {
                sums[cur-1] = cur_total;
                cur_total = i;
                cur = i;
            }
        }
        sums[cur-1] = cur_total;

        if (max_idx == 0) {
            return sums[0];
        }
        return max(
            sums[0] + deleteAndEarnOff(2),
            sums[1] + deleteAndEarnOff(3)
        );
    }
*/

    // iterative tabulation
    int deleteAndEarn(vector<int>& nums) {
        array<int, 10001> sums;
        array<int, 10001> dp;
        int max_idx = nums[0];

        for (int i=0; i<10000; ++i) {
            sums[i] = 0;
        }

        for (auto i: nums) {
            sums[i-1] += i;
            if (i-1>max_idx) { max_idx = i-1; }
        }

        if (max_idx == 0) { return sums[0]; }

        dp[max_idx] = sums[max_idx];
        dp[max_idx-1] = max(
            sums[max_idx],
            sums[max_idx-1]
        );
        for (int i=max_idx-2; i>=0; --i) {
            dp[i] = max(
                sums[i] + dp[i+2],
                dp[i+1]
            );
        }

        return dp[0];
    }
};
