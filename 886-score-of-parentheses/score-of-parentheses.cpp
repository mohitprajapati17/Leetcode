class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0, depth = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                depth++;
            } else {
                depth--;
                // Check if it's a simple "()"
                if (s[i-1] == '(') {
                    score += 1 << depth; // 2^depth
                }
            }
        }
        return score;
    }
};