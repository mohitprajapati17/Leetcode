class Solution {
public:
    void dfs(vector<vector<char>>&grid,int i,int j,int n,int m){
        grid[i][j]='m';
        vector<int> dr={-1,+1,0,0},dc={0,0,-1,+1};
      
        for(int it=0;it<4;it++){
            int new_r=dr[it]+i;
            int new_c=dc[it]+j;
            if(new_r>=0&&new_r<n&&new_c>=0&&new_c<m&&grid[new_r][new_c]=='O'){
                dfs(grid,new_r,new_c,n,m);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        for(int  i=0;i<n;i++){
            if(board[i][0]=='O') dfs(board,i,0,n,m);

            if(board[i][m-1]=='O') dfs(board,i,m-1,n,m);
        }
        for(int j=0;j<m;j++){
            if(board[0][j]=='O') dfs(board,0,j,n,m);
            if(board[n-1][j]=='O') dfs(board,n-1,j,n,m);
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<board[i][j]<<" ";
                if(board[i][j]=='m') {
                    board[i][j]='O';
                }
                else board[i][j]='X';
            }
            cout<<endl;
        }

    }
};