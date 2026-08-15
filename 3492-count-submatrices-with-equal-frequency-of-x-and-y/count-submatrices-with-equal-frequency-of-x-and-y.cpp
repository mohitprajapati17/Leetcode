class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<m;j++){
                  if(grid[i][j]=='X')grid[i][j]=1;
                  else if(grid[i][j]=='Y') grid[i][j]=-1;
                  else grid[i][j]=0;
            }
        }
        vector<vector<bool>> X(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) X[i][j]=true;
                else if(i>0&&X[i-1][j]==true)  X[i][j]=true;
                else if(j>0&&X[i][j-1]==true) X[i][j]=true;
                
            }
        }

        vector<vector<int>>  pref(n,vector<int>(m,0));

        pair<int,int>  index={-1,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 if(index.first==-1&&grid[i][j]==1){
                    index={i,j};
                 }
                 pref[i][j]+=grid[i][j];
                 if(i>0){
                    pref[i][j]+=pref[i-1][j];
                 }
                 if(j>0){
                    pref[i][j]+=pref[i][j-1];
                 }
                 if(i>0&&j>0){
                    pref[i][j]-=pref[i-1][j-1];
                 }
            }
        }
        int ans=0;
        if(index.first==-1) return 0;
        // cout<<index.first<<" "<<index.second<<endl;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<pref[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pref[i][j]==0&&X[i][j]) {
                    ans++;
                    // cout<<i<<" "<<j<<endl;
                }
            }
        }

        return  ans;

    }
};