class Solution {
public:
    int reverse (int x) {
        char s[32];
        int i = 0;

        if (x < 0) {
            s[i++] = '-';
            x = -x;
        }

        while (x != 0) {
            s[i++] = x % 10 + '0';
            x /= 10;
        }

        s[i] = '\0';
        return atoi (s);
    }
};

