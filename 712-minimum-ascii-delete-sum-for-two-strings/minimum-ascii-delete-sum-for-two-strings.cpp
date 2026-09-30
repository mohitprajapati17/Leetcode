class Solution {
public:
    int minimumDeleteSum(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i==0||j==0) continue;
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=text1[i-1]+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int lcs= dp[n][m];
        int ans=0;
        for(auto & it: text1) ans+=it;
        for(auto & it:text2) ans+=it;

        return ans-2*lcs;
    }
};