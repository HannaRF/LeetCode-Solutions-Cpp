#include <stack>

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        int n = s.length();

        if (n % 2 != 0) return false;

        for (auto i : s) {
            if (i == '(' || i == '{' || i == '[') stack.push(i);
            else {
                if (stack.empty()) return false; // Check if stack is empty before accessing top
                if ((stack.top() == '(' && i == ')') ||
                    (stack.top() == '{' && i == '}') ||
                    (stack.top() == '[' && i == ']')) {
                    stack.pop();
                } else return false; // Mismatched parentheses/brackets
            }
        }
        return stack.empty(); // Check if stack is empty at the end
    }
};
