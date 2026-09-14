class Solution {
public:
    vector<int> dp;
    int fn(int n){
        if(n==0) return 0 ;
        int ans=200001;
        if(dp[n]!=-1) return dp[n];

        for(int i=1;i<=n;i++){
            int x=i*(i+1)/2;
            if(x>n) break;
            int rem=n-x;
            if(rem==0) ans=min(ans,i);
            else ans=min(ans,i+1+fn(rem));
        }
        return dp[n]=ans;
    }
    
    int minDays(int n) {
        dp.assign(n+1,-1);
        return fn(n);
    }
};