class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ans;
        set<int> st;
        for(auto & it: nums) st.insert(it);
        vector<int> a;
        while(lower<=upper){
             if(st.find(lower)==st.end()){
                 a.push_back(lower);
             }
             else{
                if(a.size()==0) ;
                else  ans.push_back({a[0],a[a.size()-1]});
                a={};
             }
             
             lower++;
        }
        if(a.size()>0) ans.push_back({a[0],a[a.size()-1]});
        return ans;
    }
};