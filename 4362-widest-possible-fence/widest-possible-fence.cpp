class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<long long,int> freq;
        for(auto & it: planks){
            freq[it]++;
        }
        unordered_map<long long,int> mpp;
        for(auto  & [it,key]:freq){
            mpp[it*2]+=key/2;
            mpp[it]+=key;
            
        }
        vector<pair<long long,int>> vec;
        for(auto  &  [it,key] :freq){
            vec.push_back({it,key});
        }

        for(int  i=0;i<vec.size();i++){
            for(int j=i+1;j<vec.size();j++){
                int x=vec[i].first;
                int y=vec[j].first;
                int x1=vec[i].second;
                int y1=vec[j].second;
                mpp[x+y]+=min(x1,y1);
            }
        }
        int ans=0;

        for(auto  &[it,key]:mpp){
            // cout<<it<<" "<<key<<endl;
           ans=max(ans,key);
        }
        return ans;

    }
};