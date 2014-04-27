class Solution {
public:
    // Newton's method
    int sqrt (int x) {
        double y, z (1.0);

        while (int (y) - int (z) ) {
            y = z;
            z = y / 2 + (double) x / 2 / y;
        }

        return int (y);
    }
};