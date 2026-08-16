class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int index =-1;
        int dist=INT_MAX;
        for(int i=drones.size()-1;i>=0;i--){
            int  x=drones[i][0];
            int y=drones[i][1];
            int z=drones[i][2];
            if(abs(x-target[0])+abs(y-target[1])<=z) {
                 if(dist>=abs(x-target[0])+abs(y-target[1])) {
                    index=i;
                    dist=abs(x-target[0])+abs(y-target[1]);
                 }
            }
        }
        return  index;
    }
};