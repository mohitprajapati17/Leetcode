class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>  parent(n,0);
        for(int i=0;i<n;i++) parent[i]=i;


        for(int  i=1;i<n;i++){
            if(nums[i]-nums[i-1]<=maxDiff) parent[i]=parent[i-1];
        }

        vector<bool> ans;
        for(auto  & it:queries){
            int i=it[0];
            int j=it[1];
            if(parent[i]==parent[j]) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};