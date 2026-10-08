class Solution {
public:
    int rec(int ind,int k ,vector<int> & arr,vector<int>&dp){
        if(ind>=arr.size()) return 0;
        int maxi=0;
        int ans=INT_MIN;
        if(dp[ind]!=-1) return dp[ind];
        for(int i=ind;i<k+ind&&i<arr.size();i++){
           maxi=max(maxi,arr[i]);
           int cost=maxi*(i+1-ind)+rec(i+1,k,arr,dp);
           ans=max(ans,cost);
        }
        return dp[ind]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return rec(0,k,arr,dp);
    }
};