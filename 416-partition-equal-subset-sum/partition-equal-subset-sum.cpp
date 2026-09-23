class Solution {
public:
    bool rec(vector<int>&nums,int  index,int sum,vector<vector<int>>&dp){
        if(index>=nums.size()) return  false;
        if(sum==0)return true;
        if(sum<0) return false;
        if(dp[index][sum]!=-1) return dp[index][sum];
        int take=rec(nums,index+1,sum-nums[index],dp);
        int not_take=rec(nums,index+1,sum,dp);
        return dp[index][sum]=not_take||take;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto & it: nums)sum+=it;
        if(sum%2!=0) return false;
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(sum,-1));
        return rec(nums,0,sum/2,dp);
    }
};