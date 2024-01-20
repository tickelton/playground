/*

# Sum of Subarray Minimums

Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 10^9 + 7.


## Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.


## Example 2:

Input: arr = [11,81,94,43,3]
Output: 444


## Constraints:

* 1 <= arr.length <= 3 * 10^4
* 1 <= arr[i] <= 3 * 10^4

*/

/*
class Solution {
public:
    //    1
    //   1 1
    //  1 1 2
    // 3 1 2 4
    int sumSubarrayMins(vector<int>& arr) {
        int MOD = 1000000007;
        vector<vector<int>> dp(2, vector(arr.size(), 0));

        int ret = 0;
        for (int i = 0; i < arr.size(); ++i) {
            dp[0][i] = arr[i];
            ret = (ret + arr[i]) % MOD;
        }

        for (int i = 1; i < arr.size(); ++i) {
            for (int j = 0; j < arr.size() - i; ++j) {
                int cur = i % 2;
                int prev = (i - 1) % 2;
                dp[cur][j] = min(dp[prev][j], dp[prev][j + 1]);
                ret = (ret + dp[cur][j]) % MOD;
            }
        }

        return ret;
    }
};
*/

using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int length = nums.size();
        vector<int> left(length, -1);
        vector<int> right(length, length);
        stack<int> stk;

        for (int i = 0; i < length; ++i) {
            while (!stk.empty() && nums[stk.top()] >= nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }

        stk = stack<int>();

        for (int i = length - 1; i >= 0; --i) {
            while (!stk.empty() && nums[stk.top()] > nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                right[i] = stk.top();
            }
            stk.push(i);
        }

        ll sum = 0;

        for (int i = 0; i < length; ++i) {
            sum += static_cast<ll>(i - left[i]) * (right[i] - i) * nums[i] % MOD;
            sum %= MOD;
        }

        return sum;
    }
};
