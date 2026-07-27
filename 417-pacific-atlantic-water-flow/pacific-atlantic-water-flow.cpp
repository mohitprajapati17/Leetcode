class Solution {
public:
   void dfs(int i,int  j,vector<vector<int>>& heights,int n,int  m,vector<vector<int>> &pacific){
        pacific[i][j]=1;
        vector<int> dr={-1,+1,0,0};
        vector<int> dc={0,0,-1,+1};
        for(int  it=0;it<4;it++){
            int new_r=dr[it]+i;
            int new_c=dc[it]+j;

            if(new_r>=0&&new_r<n&&new_c>=0&&new_c<m&&pacific[new_r][new_c]==0){
                 if(heights[i][j]<=heights[new_r][new_c]){
                     dfs(new_r,new_c,heights,n,m,pacific);
                 }
            }

        }

   }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();


        vector<vector<int>>pacific(n,vector<int> (m,0)),atlantic(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(pacific[0][i]==0){
                dfs(0,i,heights,n,m,pacific);
            }
            
        }
        for(int  i=0;i<n;i++){
            if(pacific[i][0]==0){
                dfs(i,0,heights,n,m,pacific);
            }
        }

        for(int i=0;i<m;i++){
            if(atlantic[n-1][i]==0){
                dfs(n-1,i,heights,n,m,atlantic);
            }
            
        }

        for(int i=0;i<n;i++){
            if(atlantic[i][m-1]==0){
                dfs(i,m-1,heights,n,m,atlantic);
            }
        }
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int  j=0;j<m;j++){
                if(pacific[i][j]==1&&atlantic[i][j]==1) ans.push_back({i,j});
            }
        }

        return  ans;
        
    }
};