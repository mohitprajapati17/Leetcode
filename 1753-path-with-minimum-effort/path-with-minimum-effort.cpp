class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        int ans=INT_MIN;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        vector<vector<int>>  dist(n,vector<int> (m,INT_MAX));
        dist[0][0]=0;

        while(!pq.empty()){
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            int diff=pq.top().first;
            pq.pop();
            cout<<r<<" "<<c<<endl;
            ans=max(ans,diff);
            cout<<ans<<endl;

            if(r==n-1&&c==m-1) return ans;

            if(dist[r][c]<diff) continue;

            vector<int> dr={-1,+1,0,0};
            vector<int> dc={0,0,+1,-1};
            for(int i=0;i<4;i++){
                int new_r=dr[i]+r;
                int new_c=dc[i]+c;
                if(new_r>=0&&new_c>=0&&new_r<n&&new_c<m){
                    int w=abs(heights[r][c]-heights[new_r][new_c]);
                    if(dist[new_r][new_c]>w){
                        dist[new_r][new_c]=w;
                        pq.push({dist[new_r][new_c],{new_r,new_c}});
                    }
                }

            }
        }
        return ans;



    }
};