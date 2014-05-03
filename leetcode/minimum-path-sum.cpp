/**
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its
 * path.
 *
 * Note: You can only move either down or right at any point in time.
 */

class Solution {
public:
    int minPathSum (vector<vector<int> > &grid) {
        // space complexity O(m*n), a better algorithm reduces space to O(m)
        vector<vector<int> > path (grid);

        for (auto i = 1; i < grid.size(); ++i) {
            path[i][0] = grid[i][0] + path[i - 1][0];
        }

        for (auto i = 1; i < grid[0].size(); ++i) {
            path[0][i] = grid[0][i] + path[0][i - 1];
        }

        for (auto i = 1; i < grid.size(); ++i) {
            for (auto j = 1; j < grid[0].size(); ++j) {
                path[i][j] = grid[i][j] + min (path[i - 1][j], path[i][j - 1]);
            }
        }

        return path.back().back();
    }
};
