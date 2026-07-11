class Solution {
public:
    bool invalid =false;

    void dfs(vector<vector<int>> &grid,vector<vector<int>> &grid1, int  i,int j,int n,int m){
        grid[i][j]=-1;
        if(grid1[i][j]==0) invalid=true;

        vector<int> dr={-1,+1,0,0};
        vector<int> dc={0,0,-1,+1};
        for(int it=0;it<4;it++){
            int new_r=dr[it]+i;
            int new_c=dc[it]+j;

            if(new_r>=0&&new_r<n&&new_c>=0&&new_c<m&&grid[new_r][new_c]==1){
                dfs(grid,grid1,new_r,new_c,n,m);
            }
        }

    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int  n=grid2.size();
        int  m=grid2[0].size();
        int ans=0;

        for(int i=0;i<n;i++){
            for(int  j=0;j<m;j++){
                if(grid2[i][j]==1){
                    invalid=false;
                   dfs(grid2,grid1,i,j,n,m);
                   if(invalid  ==false)ans++;
                }
            }
        }

        return ans;

    }
};