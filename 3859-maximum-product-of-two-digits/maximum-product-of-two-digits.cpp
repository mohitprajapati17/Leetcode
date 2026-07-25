class Solution {
public:
    int maxProduct(int n) {
        string s=to_string(n);
        int maxi=0;
        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<s.size();j++){
                int x=s[i]-'0';
                int y=s[j]-'0';
                maxi=max(maxi,x*y);
            }
        }

        return maxi;
        
    }
};