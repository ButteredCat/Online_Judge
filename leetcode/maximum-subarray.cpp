/**
 * Find the contiguous subarray within an array (containing at least one
 * number) which has the largest sum.
 *
 * For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
 * the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 *
 * More practice:
 * If you have figured out the O(n) solution, try coding another solution
 * using the divide and conquer approach, which is more subtle.
 */

class Solution {
public:
    int maxSubArray (int A[], int n) {
        // Kadane's algorithm, O(n) solution.
        int ans = 0, maxn = INT_MIN;

        for (int i = 0; i < n; ++i) {
            if (ans < 0) {
                ans = 0;
            }

            ans += A[i];
            maxn = max (maxn, ans);
        }

        return maxn;
    }
};
