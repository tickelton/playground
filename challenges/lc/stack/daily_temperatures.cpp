/*

# Daily Temperatures

Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.


## Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]


## Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]


## Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]


## Constraints:

* 1 <= temperatures.length <= 10^5
* 30 <= temperatures[i] <= 100

*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        unordered_map<int, int> m;
        vector<int> ret(temperatures.size(), 0);

        for (int i=temperatures.size()-1; i>=0; --i) {
            int cur = temperatures[i];
            m[cur] = i;
            int next = 0;
            for (int t=cur+1; t<=100; ++t) {
                if (m.contains(t)) {
                    next = next == 0 ? m[t] : min(next, m[t]);
                }
            }
            ret[i] = next == 0 ? 0 : next - i;
        }

        return ret;
    }
};
