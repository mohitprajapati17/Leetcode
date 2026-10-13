class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0;i<nums.size();i++) nums[i]=abs(nums[i]);
        long long x=0;
        long long y=0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i<n/2){
               x+=1LL*nums[i]*nums[i];
            }else{
               y+=1LL*nums[i]*nums[i];
            }
        }
        return y-x;
    }
};