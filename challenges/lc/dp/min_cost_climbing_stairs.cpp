/*

# Min Cost Climbing Stairs

You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.


## Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.


## Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.


## Constraints:

* 2 <= cost.length <= 1000
* 0 <= cost[i] <= 999

*/

class Solution {
public:
    // recursion + memoziation
    /*
    array<int, 1000> dp;
    int costFromStep(vector<int>& cost, int step) {
        if (step >= cost.size()) {
            dp[cost.size()-1] = 0;
            return 0;
        }
        if (step == cost.size()-1) {
            dp[step] = cost[step];
            return cost[step];
        }

        if (dp[step] == -1) {
            dp[step] = min(
                cost[step] + costFromStep(cost, step+1),
                cost[step] + costFromStep(cost, step+2)
            );
        }
        return dp[step];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        for (int i=0; i<dp.size(); ++i) {
            dp[i] = -1;
        }

        return min(
            min(
                cost[0] + costFromStep(cost, 1),
                cost[0] + costFromStep(cost, 2)
            ),
            min(
                cost[1] + costFromStep(cost, 2),
                cost[1] + costFromStep(cost, 3)
            )
        );
    }
    */

    // iterative tabulation
    /*
    int minCostClimbingStairs(vector<int>& cost) {
        array<int, 1001> dp;
        for (int i=0; i<dp.size(); ++i) {
            if (i == cost.size() -1 ) {
                dp[i] = cost[i];
            } else {
                dp[i] = 0;
            }
        }

        for (int i=cost.size()-2; i>=0; --i) {
            dp[i] = min(
                cost[i] + dp[i+1],
                cost[i] + dp[i+2]
            );
        }

        return min(dp[0], dp[1]);
    }
    */

    // iterative tabulation; space optimized
    int minCostClimbingStairs(vector<int>& cost) {
        array<int, 2> dp = { cost[cost.size()-1], 0 };

        for (int i=cost.size()-2; i>=0; --i) {
            int newmin = min(
                cost[i] + dp[0],
                cost[i] + dp[1]
            );
            dp[1] = dp[0];
            dp[0] = newmin;
        }

        return min(dp[0], dp[1]);
    }
};
