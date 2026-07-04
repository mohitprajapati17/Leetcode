class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<pair<int,int>,int>>q;
        if(grid[0][0]!=0) return -1;
        q.push({{0,0},1});
        grid[0][0]=-1;

        while(!q.empty()){
            auto  it=q.front();
            int r=it.first.first;
            int c=it.first.second;
            int d=it.second;
            q.pop();
            cout<<r<<" "<<d<<endl;
            if(r==n-1&&c==m-1)return d;
            vector<int> dr={-1,+1,0,0,-1,+1,+1,-1};
            vector<int> dc={-1,+1,-1,+1,0,0,-1,+1};

            for(int i=0;i<8;i++){
                int new_r=dr[i]+r;
                int new_c=dc[i]+c;

                if(new_c>=0&&new_c<m&&new_r>=0&&new_r<n&&grid[new_r][new_c]==0){
                    grid[new_r][new_c]=-1;
                    q.push({{new_r,new_c},d+1});
                }
            }
        }

        return -1;

    }
};