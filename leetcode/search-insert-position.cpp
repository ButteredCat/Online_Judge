class Solution {
public:
    // binary search, O(lgn).
    int searchInsert (int A[], int n, int target) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return A[0] >= target ? 0 : 1;
        } else {
            int middle = n / 2;

            if (A[middle] == target) {
                return middle;
            } else if (A[middle] > target) {
                return searchInsert (A, middle, target);
            } else {
                return middle + searchInsert (A + middle, n - middle, target);
            }
        }
    }
};
