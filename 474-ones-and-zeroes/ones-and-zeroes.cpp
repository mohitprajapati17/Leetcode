class Solution {
public:
    int rec(vector<string>& strs,int m,int n,int index,vector<vector<vector<int>>>&dp){
         if(index>=strs.size()) return 0;
         if(m<0||n<0) return INT_MIN;
         if(dp[index][m][n]!=-1) return dp[index][m][n];
          int take=0;
         int one =0,zero=0;
         for(auto & it:strs[index]){
            if(it=='0') zero++;
            else one++;
         }
         if(one<=n&&zero<=m) take=1+rec(strs,m-zero,n-one,index+1,dp);
         int not_take=rec(strs,m,n,index+1,dp);
         return dp[index][m][n]= max(take,not_take);

    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int x=strs.size();
        vector<vector<vector<int>>>dp(x,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return rec(strs,m,n,0,dp);
    }
};