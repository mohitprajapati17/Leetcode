class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n=monsters.size();
        vector<long long> diff(n+1,0);
        for(int i=0;i<boosts.size();i++){
            diff[boosts[i][0]]+=boosts[i][2];
            diff[boosts[i][1]+1]-=boosts[i][2];
        }
        // for(int i=1;i<diff.size();i++){
        //     diff[i]+=diff[i-1];
        // }
        long long ans=0,ps=0,sum=0;
        for(int i=0;i<n;i++){
            ps+=diff[i];
            if(ps<monsters[i]) ans=max(ans,-ps+monsters[i]+sum);
            sum+=monsters[i];
        }
        return ans;
    }
};