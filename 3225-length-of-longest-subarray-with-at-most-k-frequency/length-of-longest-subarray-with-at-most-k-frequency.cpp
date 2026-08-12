class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l=0,r=0;
        map<int,int>mpp;
        int ans=0;
        int n=nums.size();
        while(r<n){
            mpp[nums[r]]++;
            if(mpp[nums[r]]<=k){
                ans=max(ans,r-l+1);
            }
            else{
                while(mpp[nums[r]]>k){
                    mpp[nums[l]]--;
                    l++;
                }


            }
            
            r++;
        }
        return ans;

    }
};