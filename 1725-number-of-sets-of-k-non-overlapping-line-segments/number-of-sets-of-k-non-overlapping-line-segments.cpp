class Solution {
public:
    int numberOfSets(int n, int K) {
    //    long long dp[1001][1001];
       vector<vector<int>> dp(1001,vector<int>(1001,0));
       int M=1e9+7;
       for(int  i=0;i<n;i++){
          dp[0][i]=1;
       }
       for(int k=1;k<=K;k++){
            int s=0;
              
              for(int i=n-1;i>=0;i--){
                
                int take=0;
                // for(int j=i+1;j<=n-1;j++){
                    // take=(take+dp[k-1][j])%M;
                    take=(take+s)%M;
                    s=(s+dp[k-1][i])%M;
                // }
                int skip=dp[k][i+1]%M;
                dp[k][i]=(take+skip)%M;
              }
       }
       return  dp[K][0];
    }
};