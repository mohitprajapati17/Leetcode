class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n=edges.size();
        vector<int> indegree(n+1,0);
        vector<int> outdegree(n+1,0);
        
        for(auto & x:edges){
            int  i=x[0];
            int j=x[1];
            // eg[i]++;eg[j]++;
            if(colors[i]=='R'){
                 if(colors[j]=='B'){
                    indegree[j]++;
                    outdegree[i]++;
                 }
                 else if(colors[j]=='W'){
                    indegree[i]++;
                     outdegree[j]++;

                 }
                 else return -1;
            }
            else if(colors[i]=='B'){
                 if(colors[j]=='W'){
                    indegree[j]++;
                     outdegree[i]++;

                 }
                 else if(colors[j]=='R'){
                    indegree[i]++;
                    outdegree[j]++;

                 }
                 else return -1;
            }
            else{
                 if(colors[j]=='R'){
                    indegree[j]++;
                     outdegree[i]++;

                 }
                 else if(colors[j]=='B'){
                    indegree[i]++;
                  outdegree[j]++;

                 }
                 else return -1;
            }
        }
        for(auto & it:outdegree){
            if(it>2) return -1;
        }
        int cnt=0;
        int ans=-1;
        for(int i=0;i<n+1;i++){
            if(indegree[i]==0) {
                // cout<<indegree[i]<<endl;
                cnt++;  ans=i;
            }

            
        }
        cout<<cnt<<endl;
        if(cnt>1)ans=-1;
        return ans;

    }
};