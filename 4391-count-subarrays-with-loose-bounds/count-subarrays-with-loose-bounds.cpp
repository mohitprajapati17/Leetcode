class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {

        int n = nums.size();
        int i = 0;
        int j = 0;
        long long cnt = 0;

        while(j < n){

            if(nums[j] >= minK && nums[j] <= maxK) cnt += (j-i+1);

            else i = j+1;

            j++;

        }

        return cnt;
        
    }
};