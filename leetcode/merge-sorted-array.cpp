class Solution {
public:
    void merge (int A[], int m, int B[], int n) {
        int *p = new int[n + m];
        int i, j, k;
        i = j = k = 0;

        while (i < m && j < n) {
            if (A[i] < B[j]) {
                p[k++] = A[i++];
            } else {
                p[k++] = B[j++];
            }
        }

        while (j < n) {
            p[k++] = B[j++];
        }

        while (i < m) {
            p[k++] = A[i++];
        }

        for (i = 0; i < m + n; ++i) {
            A[i] = p[i];
        }

        delete[] p;
    }
};