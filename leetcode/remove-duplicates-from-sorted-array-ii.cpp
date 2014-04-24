class Solution {
public:
    int removeDuplicates (int A[], int n) {
        if (n == 0 || n == 1) {
            return n;
        }

        int i, j;
        int duplicate = 1;
        int *p = new int[n];

        i = j = 0;
        p[j++] = A[i++];

        for (; i < n; ++i) {
            if (A[i] == A[i - 1]) {
                ++duplicate;

                if (duplicate <= 2) {
                    p[j++] = A[i];
                }
            } else {
                p[j++] = A[i];
                duplicate = 1;
            }
        }

        for (int i = 0; i != j; ++i) {
            A[i] = p[i];
        }

        delete[] p;
        return j;
    }
};
