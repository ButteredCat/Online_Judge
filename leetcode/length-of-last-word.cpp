/***************************************************************************
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.
***************************************************************************/
class Solution {
public:
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
