class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        vector<int>  arr;
        for(int i=0;i<nums.size();i++){
            if(i!=nums[i]) arr.push_back(i);
        }
        int ans=0;
        
        for(int i=0;i<arr.size();i++) {
            if(i==0) ans=arr[i];
            else ans=ans&arr[i];
        }
        return ans;
    }
};