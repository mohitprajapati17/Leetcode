class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n=nums.size();
        long long ans=nums[0]+nums[n-1];
        vector<long long>arr;
        for(int i=1;i<n-1;i++){
            arr.push_back(nums[i]);
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i+=2){
            if(i+1<arr.size()&&arr[i]+arr[i+1]<0){
                ans+=arr[i]+arr[i+1];
            }
        }
        return ans;
    }
};