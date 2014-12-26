/**
 * Given a string containing just the characters '(', ')', '{', '}', '['
 * and ']', determine if the input string is valid.
 *
 * The brackets must close in the correct order, "()" and "()[]{}" are all
 * valid but "(]" and "([)]" are not.
 */

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for(string::size_type i=0; i!=s.size(); ++i) {
            if(!stk.empty() && ((stk.top()=='(' && s[i]==')') || (stk.top()=='[' && s[i]==']') || (stk.top()=='{' && s[i]=='}'))) {
                stk.pop();
            } else {
                stk.push(s[i]);
            }
        }

        return stk.empty();
    }
};
