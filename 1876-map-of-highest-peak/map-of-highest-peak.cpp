class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
        vector<vector<int>> ans(n,vector<int> (m,-1));

        queue<pair<int,pair<int,int>>>  q;
        for(int i=0;i<n;i++){
            for(int  j=0;j<m;j++){
                if(isWater[i][j]==1){
                    q.push({i,{j,0}});
                    isWater[i][j]=-1;
                }
            }
        }

        while(!q.empty()){
            int  r=q.front().first;
            int  c=q.front().second.first;
            int s=q.front().second.second;
            q.pop();
            ans[r][c]=s;
            // cout<<r<<c<<s<<endl;
            vector<int> dr={-1,+1,0,0},dc={0,0,-1,+1};
            for(int i=0;i<4;i++){
                int new_r=dr[i]+r;
                int new_c=dc[i]+c;
                if(new_r>=0&&new_r<n&&new_c>=0&&new_c<m&&isWater[new_r][new_c]!=-1){
                    isWater[new_r][new_c]=-1;
                    q.push({new_r,{new_c,s+1}});
                }
            }
        }
        return ans;
    }
};