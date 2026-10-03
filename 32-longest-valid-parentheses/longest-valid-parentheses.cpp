class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1); // Base for the first valid substring

        int maxLength = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i); // Push the index of '(' onto the stack
            } else {
                st.pop(); // Pop the top element for a matching '('
                if (st.empty()) {
                    st.push(i); // Push current index as new base if stack is empty
                } else {
                    maxLength = max(maxLength, i - st.top()); // Calculate the length of current valid substring
                }
            }
        }

        return maxLength;
        
        
        
    }
};