class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
       map<int,int>mpp;
       int sum=0;
       for(auto & it: nums){
            mpp[it]++;
            sum+=it;
        }

        vector<int> arr;
        for(auto &[it,key]:mpp){
            arr.push_back(it);
        }
        sort(arr.begin(),arr.end());
        int n=arr.size();
        vector<int>dp(n,0);
        dp[0]=arr[0]*mpp[arr[0]];
        for(int i=1;i<n;i++){
            // if(mpp[arr[i]-1]>0){
            //    if(i-2>=0){
            //       dp[i]=dp[i-2]+arr[i]*mpp[arr[i]];
            //    }
            //    else dp[i]=arr[i]*mpp[arr[i]];
            // }
            // else dp[i]=dp[i-1]+arr[i]*mpp[arr[i]];
            if((arr[i]-arr[i-1])==1){
                if(i-2>=0){
                    dp[i]=max(dp[i-2]+arr[i]*mpp[arr[i]],dp[i-1]);
                }
                else dp[i]=max(dp[i-1],arr[i]*mpp[arr[i]]);
            }
            else{
                dp[i]=dp[i-1]+arr[i]*mpp[arr[i]];
            }
            
        }
        int ans=0;
        for(auto & it: dp) ans=max(ans,it);
        return ans;
    }
};