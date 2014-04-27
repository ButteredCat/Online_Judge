class Solution {
public:
    int removeElement (int A[], int n, int elem) {
        int i = 0;
        int end = n - 1;

        while (i <= end) {
            while (i <= end && A[i] == elem) {
                swap (A[i], A[end--]);
            }
            ++i;
        }

        return end + 1;
    }
};
