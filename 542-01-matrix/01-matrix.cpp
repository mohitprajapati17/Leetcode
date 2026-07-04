class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dis(n,vector<int>(m,1)), newmat(n,vector<int> (m,1));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 if(mat[i][j]==0){
                    newmat[i][j]=0;
                    q.push({{i,j},0});
                 }
            }
        }

        int dr[4]={-1,0,+1,0};
        int dc[4]={0,+1,0,-1};
        while(!q.empty()){
            auto it=q.front();
            int r=it.first.first;
            int c=it.first.second;
            int t=it.second;
            dis[r][c]=t;
            q.pop();

            for(int i =0;i<4;i++){
                int new_r=dr[i]+r;
                int new_c=dc[i]+c;
                if(new_r>=0&&new_r<n&&new_c<m&&new_c>=0&&newmat[new_r][new_c]!=0){
                    newmat[new_r][new_c]=0;
                    q.push({{new_r,new_c},t+1});

                }
            }
        }
        return dis;
    }
};