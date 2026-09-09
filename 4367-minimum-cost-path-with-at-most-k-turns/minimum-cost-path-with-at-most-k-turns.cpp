class Solution {
public:
    int vis[75][75][75][5];
    int minCost(vector<vector<int>>& grid, int k) {
        priority_queue<vector<int>> p;
        p.push({-grid[0][0],0,0,0,4});
        int n=grid.size(),m=grid[0].size();
        memset(vis,-1,sizeof(vis));
        vis[0][0][0][4]=grid[0][0];
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        while(!p.empty()){
            auto v=p.top();
            p.pop();
            int d=-v[0],r=v[1],c=v[2],turns=v[3],dir=v[4];
             if(d>vis[r][c][turns][dir]) continue;
            for(int i=0;i<4;i++){
                int nr=r+dx[i],nc=c+dy[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    
                    int turn=(i!=dir)&&(dir!=4);
                    int nturns=turns+turn;
                    if(nturns>k) continue;
                    int dist=vis[nr][nc][nturns][i];
                    if(dist==-1) dist=1e9;
                    int nd=d+grid[nr][nc];
                    if(dist>nd){
                        vis[nr][nc][nturns][i]=nd;
                        p.push({-nd,nr,nc,nturns,i});
                    }
                }
            }
        }
        int ans=1e9;
        for(int i=0;i<5;i++){
            for(int j=0;j<=k;j++){ 
            if(vis[n-1][m-1][j][i]!=-1)
            ans=min(ans,vis[n-1][m-1][j][i]);
            }
        }
        if(ans==1e9) return -1;
        return ans;
    }
};