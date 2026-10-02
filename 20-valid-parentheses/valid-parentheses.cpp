class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;

    // Iterate through each character in the string
    for (char& c : s) {
        // If it's an opening bracket, push it onto the stack
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        // If it's a closing bracket, check if it matches the top of the stack
        else {
            if (st.empty()) {
                return false; // No matching opening bracket
            }
            char top = st.top();
            st.pop();
            if ((c == ')' && top != '(') || 
                (c == '}' && top != '{') || 
                (c == ']' && top != '[')) {
                return false; // Mismatched brackets
            }
        }
    }

    // If the stack is empty, all brackets were matched
    return st.empty();
    }
};