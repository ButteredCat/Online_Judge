/**
 * Evaluate the value of an arithmetic expression in Reverse Polish
 * Notation.
 *
 * Valid operators are +, -, *, /. Each operand may be an integer or another
 * expression.
 *
 * Some examples:
 *   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 *   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */

class Solution {
public:
    int evalRPN (vector<string> &tokens) {
        stack<int> opnd;

        for (vector<string>::iterator iv = tokens.begin(); iv != tokens.end(); ++iv ) {
            if (*iv == "+" || *iv == "-" || *iv == "*" || *iv == "/") {
                int a = opnd.top();
                opnd.pop();
                int b = opnd.top();
                opnd.pop();

                switch ( (*iv) [0] ) {
                case '+':
                    opnd.push (a + b);
                    break;
                case '-':
                    opnd.push (b - a);
                    break;
                case '*':
                    opnd.push (a * b);
                    break;
                case '/':
                    opnd.push (b / a);
                    break;
                default:
                    break;
                }
            } else {
                opnd.push (stoi (*iv) );
            }
        }

        return opnd.top();
    }
};
