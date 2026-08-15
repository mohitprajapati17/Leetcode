class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x=0;
        bool zero=true;
        for(auto &it:nums) {
            x=x^it;
            if(it!=0)zero=false;
        }
        if(zero) return 0;
        if(x==0) return nums.size()-1;
        return nums.size();
        
    }
};