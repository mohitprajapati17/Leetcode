class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        int p1=0,p2=0;
        int n=series1.size();
        int m=series2.size();
        vector<vector<int>> ans;
        while(p1<n&&p2<m){
            int x=min(series1[p1][0],series2[p2][0]);
            int y=series1[p1][1]+series2[p2][1];
            ans.push_back({x,y});
            if(series1[p1][0]==x) p1++;
            if(series2[p2][0]==x)  p2++;

        }

        while(p1<n) {
            ans.push_back({series1[p1][0],series1[p1][1]});
            p1++;
        }
        while(p2<m) {
            ans.push_back({series2[p2][0],series2[p2][1]});
            p2++;
        }

        return ans;
    }
};