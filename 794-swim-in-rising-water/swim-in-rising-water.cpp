class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int   n=grid.size();
        int m=grid[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        int ans =INT_MIN;
        while(!pq.empty()){
            int cost =pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            grid[r][c]=-1;
            pq.pop();
            ans=max(ans,cost);
            if(r==n-1&&c==m-1) return ans;

            vector<int>dr={-1,+1,0,0},dc={0,0,+1,-1};
            for(int i=0;i<4;i++){
                int new_r=dr[i]+r;

                int new_c=dc[i]+c;
                if(new_r>=0&&new_c>=0&&new_r<n&&new_c<m&&grid[new_r][new_c]!=-1){
                    pq.push({grid[new_r][new_c],{new_r,new_c}});
                }
            }
        }

        return ans;
    }
};