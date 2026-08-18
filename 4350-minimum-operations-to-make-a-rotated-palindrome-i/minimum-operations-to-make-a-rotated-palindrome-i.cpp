class Solution {
public:
    int minOperations(string s) {
        int ans=INT_MAX;
        int n=s.size();
        s+=s;
        cout<<s<<endl;
        
        for(int i=0;i<n;i++){
            int j=i,k=i+n-1;
            int  diff=0;
            while(j<=k){
                int d=abs(s[j]-s[k]);
                // cout<<j<<" "<<k<<endl;
                diff+=min(d,26-d);
                k--,j++;
            }
            // cout<<diff<<endl;
            ans=min(ans,diff+i);
        }
        return ans;
    }
};