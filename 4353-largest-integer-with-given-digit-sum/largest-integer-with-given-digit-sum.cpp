class Solution {
public:
    int largestInteger(int n, int s) {
        string ans="";
        while(n--){
            if(s>=9) {
                ans+='9';
                s-=9;
            }
            else {
                ans+=s+'0';
                s=0;
                };
            

        }
        if(s>0) return -1;
        return stoi(ans);
    }
};