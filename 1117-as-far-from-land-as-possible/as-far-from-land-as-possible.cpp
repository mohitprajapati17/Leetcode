class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();

       queue<pair<pair<int,int>,int>> q;
       for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) q.push({{i,j},0});
            }
       } 
       int maxi = 0;

       while(!q.empty()){
           auto it =q.front();
           int r=it.first.first;
           int  c=it.first.second;
           int d=it.second;
           maxi=max(maxi,d);


           q.pop();
           vector<int> dr={-1,+1,0,0};
           vector<int> dc={0,0,+1,-1};

           for(int i=0;i<4;i++){
              int new_r=dr[i]+r;
              int new_c=dc[i]+c;

              if(new_r>=0&&new_c>=0&&new_c<m&&new_r<n&&grid[new_r][new_c]==0){
                grid[new_r][new_c]=1;
                q.push({{new_r,new_c},d+1});

              }
           }
       }
       if(maxi==0)   return -1;
       return maxi;
    }
};