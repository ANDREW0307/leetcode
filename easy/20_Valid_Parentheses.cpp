/*

    idea: push every opening bracket onto the stack. whenever we encounter a closing bracket, we check the top of the stack to see if the latest opening bracket (which will be at the top of the stack) matches our current closing bracket.

*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> charStack;
        unordered_map<char, char> map;
        
        map[')'] = '(';
        map[']'] = '[';
        map['}'] = '{';

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                // we only push opening brackets onto the stack
                charStack.push(c);
            } 
            if (c == ')' || c == ']' || c == '}') {
                // if the charStack is empty, we immediately know that the string is not valid because there is a closing bracket without any opening brackets
                if (charStack.empty()) {
                    return false;
                }
                if (charStack.top() == map[c]) {
                    // if the most recent opening bracket matches the current closing bracket, we know this is a valid opening and closing, and we can move on
                    charStack.pop();
                    continue;
                } else {
                    return false;
                }
            }
        }
        // if the stack is not empty at the end, there must be an opening bracket that was never closed
        if (!charStack.empty()) {
            return false;
        }
        return true;
    }
};
