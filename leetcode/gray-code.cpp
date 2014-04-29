class Solution {
public:
    vector<int> grayCode (int n) {
        vector<int> v (1, 0);

        if (n > 0) {
            v.push_back (1);
            int mask = 2;

            for (int i = 1; i < n; ++i) {
                vector<int>::size_type j = v.size();

                while (j--) {
                    v.push_back (v[j] | mask);
                }

                mask <<= 1;
            }
        }

        return v;
    }
};
