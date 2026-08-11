class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int  ans=nums[0]+1;
        int sum=nums[0];
        int n=nums.size();
        map<int,int> mpp;
        for(auto  & it: nums) mpp[it]++;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1) sum+=nums[i];
            else  break;
        } 

        while(mpp[sum]>0){
            sum++;
        }
        
        return sum;
    }
};