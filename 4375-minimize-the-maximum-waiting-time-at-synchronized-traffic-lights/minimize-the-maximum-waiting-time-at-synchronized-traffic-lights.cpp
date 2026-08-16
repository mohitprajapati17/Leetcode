class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        sort(lights.begin(),lights.end());
        for(int i=0;i<arrivalTime.size();i++){
            arrivalTime[i]=arrivalTime[i]%period;
        }
        int ans=0;
        for(auto & it: arrivalTime){
            if(it>=lights[lights.size()-1]){
                ans=max(ans,period-it);
            }
        }

        return ans;

    }
};