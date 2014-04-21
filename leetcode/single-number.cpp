class Solution
{
public:
    int singleNumber (int A[], int n)
    {
        int Xor = A[0];

        for (int i = 1; i != n; ++i)
        {
            Xor ^= A[i];
        }

        return Xor;
    }
};
