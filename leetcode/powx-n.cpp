class Solution {
public:
    double pow (double x, int n) {
        if (n == 0) {
            return 1.0;
        } else if (abs (n) == 1) {
            return n == 1 ? x : 1.0 / x;
        } else {
            if (n < 0) {
                x = 1.0 / x;
                n = -n;
            }

            double y = pow (x, n / 2);
            return n % 2 ? y * y * x : y * y;
        }
    }
};