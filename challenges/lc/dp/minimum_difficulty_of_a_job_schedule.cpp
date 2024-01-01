/*

# Minimum Difficulty of a Job Schedule

You want to schedule a list of jobs in d days. Jobs are dependent (i.e To work on the ith job, you have to finish all the jobs j where 0 <= j < i).

You have to finish at least one task every day. The difficulty of a job schedule is the sum of difficulties of each day of the d days. The difficulty of a day is the maximum difficulty of a job done on that day.

You are given an integer array jobDifficulty and an integer d. The difficulty of the ith job is jobDifficulty[i].

Return the minimum difficulty of a job schedule. If you cannot find a schedule for the jobs return -1.


## Example 1:

Input: jobDifficulty = [6,5,4,3,2,1], d = 2
Output: 7
Explanation: First day you can finish the first 5 jobs, total difficulty = 6.
Second day you can finish the last job, total difficulty = 1.
The difficulty of the schedule = 6 + 1 = 7


## Example 2:

Input: jobDifficulty = [9,9,9], d = 4
Output: -1
Explanation: If you finish a job per day you will still have a free day. you cannot find a schedule for the given jobs.


## Example 3:

Input: jobDifficulty = [1,1,1], d = 3
Output: 3
Explanation: The schedule is one job per day. total difficulty will be 3.


## Constraints:

* 1 <= jobDifficulty.length <= 300
* 0 <= jobDifficulty[i] <= 1000
* 1 <= d <= 10

*/

class Solution {
public:
/*
    vector<vector<int>> dp;
    int minFrom(int offset, vector<int>& jobDifficulty, int d) {
        cout << "minFrom " << offset << " " << d ;
        if (dp[offset][d] != -2) {
            cout << "=" << dp[offset][d];
            return dp[offset][d];
        }
        if (jobDifficulty.size() < d) { return -1; };
        if (d == 1) {
            return *min_element(jobDifficulty.begin()+offset, jobDifficulty.end());
        }

        int minD = INT_MAX;
        int max_day = -1;
        for (int i=offset; i<=jobDifficulty.size() - d; ++i) {
            if (jobDifficulty[i] > max_day) {
                max_day = jobDifficulty[i];
            }

            minD = min(
                minD,
                max_day + minFrom(i+1, jobDifficulty, d-1)
            );
        }
        dp[offset][d] = minD;
        cout << "=" << dp[offset][d] << "\n";
        return minD;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        //cout << jobDifficulty.size() << " " << d << "\n";
        if (jobDifficulty.size() < d) { return -1; };
        if (d == 1) {
            return *min_element(jobDifficulty.begin(), jobDifficulty.end());
        }
        dp = vector(jobDifficulty.size()+1, vector(jobDifficulty.size()+1, -2));

        int minD = INT_MAX;
        int max_day = -1;
        for (int i=0; i<=jobDifficulty.size() - d; ++i) {
            cout << "main " << i << " " << d <<"\n";
            if (jobDifficulty[i] > max_day) {
                max_day = jobDifficulty[i];
            }
            minD = min(
                minD,
                max_day + minFrom(i+1, jobDifficulty, d-1)
            );
        }
        return minD;
    }
*/

    vector<vector<int>> dp;
    int minDifficultyFrom(int offset, vector<int>& jobDifficulty, int d) {
        if (d == 0) { return 0; }
        if (dp[d][offset] != -2) { return dp[d][offset]; }

        if (d == 1) {
            dp[d][offset] = *max_element(jobDifficulty.begin()+offset, jobDifficulty.end());
            return dp[d][offset];
        }
        if (jobDifficulty.size() - offset < d) { return -1; }
        if (d == jobDifficulty.size() - offset) {
            dp[d][offset] = jobDifficulty[offset] + minDifficultyFrom(offset+1,  jobDifficulty, d-1);
            return dp[d][offset];
        }

        int maxToday = jobDifficulty[offset];
        int minTotal = -1;
        for (int i=offset; i<=jobDifficulty.size()-d; ++i) {
            if (maxToday < jobDifficulty[i]) {
                maxToday = jobDifficulty[i];
            }
            int newMin = minDifficultyFrom(i+1,  jobDifficulty, d-1);
            if (newMin == -1) { break; }
            if (minTotal == -1) {
                minTotal = newMin + maxToday;
            } else {
                minTotal = min(
                    minTotal,
                    newMin + maxToday
                );
            }
        }
        dp[d][offset] = minTotal;
        return minTotal;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        dp = vector(d+1, vector(jobDifficulty.size()+1, -2));
        return minDifficultyFrom(0, jobDifficulty, d);
    }
};
