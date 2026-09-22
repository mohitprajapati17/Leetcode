class Solution {
public:
    long long rec(int sum,int  index,vector<int>& coins,vector<vector<int>> &dp){
        if(sum<0||index>=coins.size()) return INT_MAX;
        if(sum==0)return 0;
        if(dp[index][sum]!=-1) return dp[index][sum];
        long long take=1 + rec(sum-coins[index],index,coins,dp);

        long  long not_take=rec(sum,index+1,coins,dp);
        return dp[index][sum]=min(take,not_take);
    
    }

    int coinChange(vector<int>& coins, int amount) {
        int  n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        int x= rec(amount,0,coins,dp);
        if(x==INT_MAX) return -1;
        return  x;
    }
};