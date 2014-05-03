/**
 * Follow up for "Unique Paths":
 *
 * Now consider if some obstacles are added to the grids. How many unique
 * paths would there be?
 *
 * An obstacle and empty space is marked as 1 and 0 respectively in the
 * grid.
 *
 * For example,
 * There is one obstacle in the middle of a 3x3 grid as illustrated below.
 *
 * [
 *  [0,0,0],
 *  [0,1,0],
 *  [0,0,0]
 * ]
 * The total number of unique paths is 2.
 *
 * Note: m and n will be at most 100.
 */

class Solution {
private:
    const int OBSTACLE = 1;
    const int EMPTY = 0;
public:
	// space complexity O(m*n), there is a better implementation with space complexity O(n)
    int uniquePathsWithObstacles (vector<vector<int> > &obstacleGrid) {
        vector<vector<int> > grid (obstacleGrid.size(), vector<int> (obstacleGrid[0].size(), 0) );

        for (auto i = 0; i < grid.size(); ++i) {
            if (obstacleGrid[i][0] != OBSTACLE) {
                grid[i][0] = 1;
            } else {
                break;
            }
        }

        for (auto i = 0; i < grid[0].size(); ++i) {
            if (obstacleGrid[0][i] != OBSTACLE) {
                grid[0][i] = 1;
            } else {
                break;
            }
        }

        for (auto i = 1; i < grid.size(); ++i) {
            for (auto j = 1; j < grid[0].size(); ++j) {
                if (obstacleGrid[i][j] != OBSTACLE) {
                    grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
                }
            }
        }

        return grid.back().back();
    }
};
