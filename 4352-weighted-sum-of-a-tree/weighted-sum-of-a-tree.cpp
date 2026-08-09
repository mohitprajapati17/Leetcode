class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int  n=parent.size();
        vector<vector<int>>adj(n);

        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
        queue<int>q;
        vector<int> depth(n,0);
        depth[0]=1;
        q.push(0);
        int h=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto &  it: adj[node]){
                depth[it]=depth[node]+1;
                h=max(h,depth[it]);
                q.push(it);
            }
        }
        
        long long ans=0;
        for(int i=0;i<nums.size();i++){
             ans=ans+1LL*nums[i]*1LL*(h-depth[i]+1);
        }
        return ans;

    }
};