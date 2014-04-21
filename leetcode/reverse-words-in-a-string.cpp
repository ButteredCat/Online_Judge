class Solution
{
public:
    void reverseWords (string &s)
    {
        string r, word;
        istringstream is (s);

        is >> r;

        while (is >> word)
            r = word + " " + r;

        s = r;
    }
};
