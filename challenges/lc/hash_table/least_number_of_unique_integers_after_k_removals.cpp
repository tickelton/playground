/*

# Least Number of Unique Integers after K Removals

Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.


## Example 1:

Input: arr = [5,5,4], k = 1
Output: 1
Explanation: Remove the single 4, only 5 is left.


## Example 2:

Input: arr = [4,3,1,1,3,3,2], k = 3
Output: 2
Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.


## Constraints:

* 1 <= arr.length <= 10^5
* 1 <= arr[i] <= 10^9
* 0 <= k <= arr.length

*/

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        for (auto n : arr) {
            if (m.contains(n)) {
                m[n]++;
            } else {
                m[n] = 1;
            }
        }

        vector<int> f;
        for (auto [k, v] : m) {
            f.push_back(v);
        }

        sort(f.begin(), f.end());
        int total = f.size();
        for (auto v : f) {
            if (v <= k) {
                k -= v;
                --total;
            } else {
                break;
            }
        }

        return total;
    }
};
