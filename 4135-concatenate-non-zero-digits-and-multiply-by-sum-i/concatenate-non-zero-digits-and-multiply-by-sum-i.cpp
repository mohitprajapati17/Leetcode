class Solution {
public:
    long long sumAndMultiply(int n) {
        string x=to_string(n);
        string y="";
        int  sum=0;
        for(auto & it: x){
            if(it!='0') {
                y+=it;
                sum+=it-'0';
            }
        }
        if(y=="")y+='0';

        return 1LL*sum*stoi(y);
    }
};