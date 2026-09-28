class Solution {
public:
    int maxDepth(string s) {
        int cnt=0;
        int max1=0;
        for(auto &i :s){
            if(i=='('){
                cnt++;
                max1=max(cnt,max1);
            }
            else if(i==')'){
                cnt--;
            }
        }
        return max1;
    }
};