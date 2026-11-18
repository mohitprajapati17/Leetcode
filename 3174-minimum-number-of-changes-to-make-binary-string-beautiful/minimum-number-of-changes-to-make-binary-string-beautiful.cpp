class Solution {
public:
    int minChanges(string s) {
        int ans=0;
        int  n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]!=s[i+1]){
                //  cout<<i<<endl;
                 ans++;
            }
            i+=1;
        }
        return ans;
    }
};