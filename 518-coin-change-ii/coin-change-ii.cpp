class Solution {
public:
   long long rec(int sum,int  index,vector<int>& coins,vector<vector<int>> &dp){
        if(sum<0||index>=coins.size()) return 0;
        if(sum==0)return 1;
        if(dp[index][sum]!=-1) return dp[index][sum];
        long long take= rec(sum-coins[index],index,coins,dp);

        long  long not_take=rec(sum,index+1,coins,dp);
        return dp[index][sum]=take+not_take;
    
    }
    int change(int amount, vector<int>& coins) {
        int  n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        int x= rec(amount,0,coins,dp);
        if(x==0) return 0;
        return  x;
    }
};