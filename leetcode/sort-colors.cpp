class Solution {
public:
    void sortColors (int A[], int n) {
        int count[3] = {0};

        for (int i = 0; i < n; ++i) {
            ++count[A[i]];
        }

        int k = 0;

        for (int i = 0; i < 3; ++i) {
            while (count[i]--) {
                A[k++] = i;
            }
        }
    }
};