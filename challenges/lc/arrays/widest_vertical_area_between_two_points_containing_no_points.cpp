/*

# Widest Vertical Area Between Two Points Containing No Points

Given n points on a 2D plane where points[i] = [xi, yi], Return the widest vertical area between two points such that no points are inside the area.

A vertical area is an area of fixed-width extending infinitely along the y-axis (i.e., infinite height). The widest vertical area is the one with the maximum width.

Note that points on the edge of a vertical area are not considered included in the area.


## Example 1:

 10 |    |  |  |
    |    |  |  |
  9 |    |  |  x
    |    |  |  |
  8 |    |  |  |
    |    |  |  |
  7 |    |  x  x
    |    |  |  |
  6 |    |  |  |
    |    |  |  |
  5 |    |  |  |
    |    |  |  |
  4 |    x  |  |
    |    |  |  |
     ----------------
      6  7  8  9  10

Input: points = [[8,7],[9,9],[7,4],[9,7]]
Output: 1
Explanation: Both the red and the blue area are optimal.

## Example 2:

Input: points = [[3,1],[9,0],[1,0],[1,4],[5,3],[8,8]]
Output: 3


## Constraints:

* n == points.length
* 2 <= n <= 10^5
* points[i].length == 2
* 0 <= xi, yi <= 10^9

*/

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int> x_coords;
        for (const auto &p: points) {
            x_coords.insert(p[0]);
        }

        int max_diff = 0;
        for (auto it = x_coords.begin(); it != x_coords.end(); ++it) {
            if (it == x_coords.begin()) { continue; }
            int diff = *(it) - *(--it);
            if (diff > max_diff) {
                max_diff = diff;
            }
            ++it;
        }

        return max_diff;
    }
};
