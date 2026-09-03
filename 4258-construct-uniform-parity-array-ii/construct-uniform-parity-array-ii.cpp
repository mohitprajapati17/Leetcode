class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(),nums1.end());
        int even=0,odd=0;

        for(auto  & it: nums1){
            if(it%2==0) even++;
            else odd++;
        }
        if(even&&odd){
            if(nums1[0]%2==0) return false;
        }
        return true;
    }
};