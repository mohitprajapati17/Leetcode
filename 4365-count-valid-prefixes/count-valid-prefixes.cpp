class Solution {
public:
    int countValidPrefixes(string s) {
        int o=0,e=0;
        int ans=0;
        for(auto  &  it: s){
            if(it=='0') o++;
            else e++;

            if(abs(o-e)<=1) ans++;
        }
        return ans;
    }
};