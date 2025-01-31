#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        
        for (char c : s) {
            // If the character is an opening bracket, push it onto the stack
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } 
            // If the character is a closing bracket, check if it matches the top of the stack
            else if (c == ')' || c == '}' || c == ']') {
                if (stack.empty()) {
                    return false; // No opening bracket to match with
                }
                char top = stack.top();
                stack.pop();
                
                // Check if the top of the stack matches the corresponding opening bracket
                if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                    return false;
                }
            }
        }
        
        // If the stack is empty, all brackets were matched, otherwise return false
        return stack.empty();
    }
};