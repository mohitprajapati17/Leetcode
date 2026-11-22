class Solution {
public:
    bool checkString(string s) {
        int n=s.size();
        int a=-1,b=n;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='a'){
                a=i;
            }
        }
        for(int i=0;i<s.size();i++){
            if(s[i]=='b'){
                b=i;
                break;
            }
        }

        if(a<b)return true;
        return false;
    }
};