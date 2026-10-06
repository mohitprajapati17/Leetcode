class Solution {
public:
    bool isPalindrome(int  i,int k,string &s){
        while(i<k){
            if(s[i]!=s[k]){
                return  false;
            }
            i++;
            k--;
        }
        return true;
    }
    int rec(int i,int n,string &s,vector<int>& dp){
        if(i==n) return 0;
        int mini=INT_MAX;
        if(dp[i]!=-1)  return dp[i];
        for(int k=i;k<n;k++){
            // int cost=0;
            if(isPalindrome(i,k,s)){
                int cost =1+rec(k+1,n,s,dp);
                 mini=min(cost,mini);
            }
           
        }
        return dp[i]=mini;
    }
    int minCut(string s) {
        vector<int> dp(s.size(),-1);
        return rec(0,s.size(),s,dp)-1;
    }
};