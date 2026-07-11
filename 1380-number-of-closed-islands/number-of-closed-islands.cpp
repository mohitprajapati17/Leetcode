class Solution {
public:
    bool valid=true;
    void dfs(vector<vector<int>>& grid, int n, int m , int i,int j){
        grid[i][j]=-1;
        if(i==0||j==0||i==n-1||j==m-1) valid=false;
        vector<int> dr={0,0,-1,+1},dc={-1,+1,0,0};

        for(int it=0;it<4;it++){
            int new_r=dr[it]+i;
            int new_c= dc[it]+j;

            
            if(new_r>=0&&new_r<=n-1&&new_c>=0&&new_c<=m-1&&grid[new_r][new_c]==0){

                
                dfs(grid,n,m,new_r,new_c);
            }

        }

    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int  m=grid[0].size();
        int ans=0;
        for(int  i=0;i<n;i++){
            for(int  j=0;j<m;j++){
                if(grid[i][j]==0){
                    valid=true;
                    dfs(grid,n,m,i,j);
                    if(valid)  ans++;
                }
            }
        }

        return ans;

    }
};