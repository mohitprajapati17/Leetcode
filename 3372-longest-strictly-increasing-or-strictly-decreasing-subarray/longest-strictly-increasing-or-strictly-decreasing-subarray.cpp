class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> dec(n);
        dec[n-1]=n-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                dec[i]=dec[i+1];
            }
            else dec[i]=i;
        }

        vector<int> inc(n);
        inc[n-1]=n-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                inc[i]=inc[i+1];
            }
            else inc[i]=i;
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,max(dec[i]-i+1,inc[i]-i+1));
        }
        return maxi;
    }
};