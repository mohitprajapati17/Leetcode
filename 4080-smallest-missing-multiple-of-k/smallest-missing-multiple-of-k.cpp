class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int> st;
        for(auto & it: nums) st.insert(it);

        for(int i=1;i<=101;i++){
            if(st.find(k*i)==st.end()) return k*i;
        }
        return 0;
    }
};