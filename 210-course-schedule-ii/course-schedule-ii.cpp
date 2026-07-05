class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);
        for(auto & it: prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
             if(indegree[i]==0){
                q.push(i);
             }
        }

        vector<int> ans;
        while(!q.empty()){
             int x=q.front();
             q.pop();
             ans.push_back(x);
             for(auto & it:adj[x]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
             }
        }
        if(ans.size()!=numCourses) return {};
        return ans;
    }
};