class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {


        if(source==target) return 0;

        unordered_map<int,vector<int>> mpp;
        queue<int> q;
        for(int r=0;r<routes.size();r++){
            for(auto & x:routes[r]){
                mpp[x].push_back(r);
            }
        }

        vector<bool> vis(501,false);

        for(auto & route:mpp[source]){
            q.push(route);
            vis[route]=true;

        }

        int busCount=1;
        while(!q.empty()){
            int size=q.size();

            while(size--){
                int  route = q.front();
                q.pop();
                for(auto & it: routes[route]){
                    if(it==target) return busCount;

                    for(auto &i:mpp[it]){
                        if(vis[i]==false){
                            q.push(i);
                            vis[i]=true;
                        }
                    }
                }
            }
            busCount++;
        }
        return -1;



    }
};