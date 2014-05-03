/**
 * A robot is located at the top-left corner of a m x n grid (marked 'Start'
 * in the diagram below).
 *
 * The robot can only move either down or right at any point in time. The
 * robot is trying to reach the bottom-right corner of the grid (marked
 * 'Finish' in the diagram below).
 *
 * How many possible unique paths are there?
 *
 * Note: m and n will be at most 100.
 *
 * Naive algorithm, too slow:
 *
 * int uniquePaths (int m, int n) {
 * 		if (m == 1 || n == 1) {
 * 		    return 1;
 * 		} else {
 * 		    return uniquePaths (m - 1, n) + uniquePaths (m, n - 1);
 * 		}
 * }
 *
 */

class Solution {
public:
    int uniquePaths (int m, int n) {
        vector<vector<int> > grid;

        for (int i = 0; i < m; ++i) {
            vector<int> aRow (n, 1);

            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0) {
                    aRow[j] = 1;
                } else {
                    aRow[j] = grid[i - 1][j] + aRow[j - 1];
                }
            }

            grid.push_back (aRow);
        }

        return grid[m - 1][n - 1];
    }
};
