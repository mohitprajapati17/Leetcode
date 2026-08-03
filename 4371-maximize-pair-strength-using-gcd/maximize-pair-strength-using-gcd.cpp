class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int64_t x=1LL*__gcd(nums[i],nums[j])*__gcd(nums[i],nums[j]);
                 ans=max(ans, 1LL*nums[i]*nums[j]/x);

                //  cout<<__gcd(nums[i],nums[j])<<endl;
            }
        }
        return ans;
    }
};