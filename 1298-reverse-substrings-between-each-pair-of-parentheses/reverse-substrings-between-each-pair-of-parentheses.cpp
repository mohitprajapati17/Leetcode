class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;

        for(int i=0;i<s.size();i++){
            if(st.empty()) st.push(s[i]);
            else{
                if(s[i]==')'){
                    string x="";
                    while(!st.empty()&&st.top()!='('){

                         x+=st.top();
                         st.pop();
                    }
                    st.pop();
                    cout<<x<<endl;
                    for(auto &it:x) st.push(it);

                }
                else{
                   st.push(s[i]);

                }
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());

        return ans;
    }
};