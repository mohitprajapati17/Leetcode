class Solution {
public:
    int minimumPushes(string word) {
        map<char,int> mpp;
        vector<pair<int,char>> arr;
        for(auto &   it: word) mpp[it]++;
        for(auto &  [it,key]:mpp) arr.push_back({key,it});
        sort(arr.begin(),arr.end());
        int ans=0;
        int y=8;

         int x=1;
    
        for(auto & a:arr){
            // cout<<it<<endl;
            int it =a.first;
            char key=a.second;
          
           
           if(y>0){
            // cout<<it<<endl;
            ans+=it*x;
            y--;
           }
           if(y==0){
            y=8;
            x++;
           }
        }
        return ans;

    }
};