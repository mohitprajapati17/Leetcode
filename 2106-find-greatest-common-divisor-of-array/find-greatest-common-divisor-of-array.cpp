class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi=nums[nums.size()-1];
        int mini=nums[0];
        return __gcd(maxi,mini);
    }
};