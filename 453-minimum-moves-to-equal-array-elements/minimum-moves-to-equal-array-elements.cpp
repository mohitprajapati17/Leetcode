class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ele =nums[0];

        int ans=0;
        for(auto & it:nums)ans+=abs(it-ele);

        return  ans;
        }
};