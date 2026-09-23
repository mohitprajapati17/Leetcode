class Solution {
public:
    long long rec(int sum,int  index,vector<int>& coins,vector<vector<int>> &dp){
        if(sum<0||index>=coins.size()) return 0;
        if(sum==0)return 1;
        if(dp[index][sum]!=-1) return dp[index][sum];
        long long take= rec(sum-coins[index],0,coins,dp);

        long  long not_take=rec(sum,index+1,coins,dp);
        return dp[index][sum]=take+not_take;
    
    }
    int combinationSum4(vector<int>& nums, int target) {
        int  n=nums.size();
        vector<vector<int>> dp(n,vector<int> (target+1,-1));
        int x= rec(target,0,nums,dp);
        if(x==0) return 0;
        return  x;
    }
};