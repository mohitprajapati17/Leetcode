class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt=0;
        int  n=s.size();
        stack<char> st;
        for(auto & it:s){
            if(st.empty()&&it==')'){
                cnt++;
                continue;
            }
            else if( it=='('){
                st.push(it);
            }else if( it==')'){
                st.pop();
            }
        }
        return st.size()+cnt;
        
    }
};