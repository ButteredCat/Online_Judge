/**
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways
 * can you climb to the top?
 */

class Solution {
public:
    int climbStairs (int n) {
        vector<int> stairs (n + 1, 1);

        for (int i = 2; i <= n; ++i) {
            stairs[i] = stairs[i - 1] + stairs[i - 2];
        }

        return stairs[n];
    }
};
