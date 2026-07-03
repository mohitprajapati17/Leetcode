class Solution {
public:
    int dfs(vector<vector<int>> & grid,int i,int j, int n,int  m ){
        grid[i][j]=0;
        vector<int> dr={-1,+1,0,0},dc={0,0,-1,+1};
        int ans=1;
        for(int it=0;it<4;it++){
            int new_r=dr[it]+i;
            int new_c=dc[it]+j;
            if(new_r>=0&&new_r<n&&new_c>=0&&new_c<m&&grid[new_r][new_c]==1){
                ans+=dfs(grid,new_r,new_c,n,m);
            }
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    
                    ans=max(ans,dfs(grid,i,j,n,m));
                }
            }
        }
        return ans;
        
    }
};