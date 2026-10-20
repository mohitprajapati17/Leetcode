class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int  n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        pair<int,int> ans;
        vis[0][0]=true;
        int i=0,j=0;
        while(i>=0&&j>=0&&i<n&&j<m){
            ans={i,j};
            // cout<<i<<" "<<j<<endl;
            if(grid[i][j]=='R'){
                if(j+1>=m||(vis[i][j+1])) break;
                 else j++; vis[i][j]=true;continue;
            }
            if(grid[i][j]=='L'){
                if(j-1<0||vis[i][j-1]) break;
                else j--;vis[i][j]=true;continue;
            }
            if(grid[i][j]=='U'){
                if(i-1<0||vis[i-1][j]) break;
               else i--;vis[i][j]=true;continue;
            }
            if(grid[i][j]=='D'){
                if(i+1>=n||vis[i+1][j]) break;
                else i++;vis[i][j]=true;continue;
            }
        }
        return {ans.first,ans.second};

    }
};