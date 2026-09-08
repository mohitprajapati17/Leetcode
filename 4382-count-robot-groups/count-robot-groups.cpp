class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        map<int,int>  mpp;
         int n=position.size();
        for(int i=0;i<n-1;i++){
            if(position[i+1]-position[i]<=distance){
                continue;
            }
            else mpp[position[i]]=speed[i];
        }
        mpp[position[n-1]]=speed[n-1];
        vector<int> p,s;
        for(auto & [it,key]:mpp){
          p.push_back(it);
          s.push_back(key);
        }
        int ans=p.size();
        cout<<p.size();
        int last=s[ans-1];
        for(int i=p.size()-1;i>=0;i--){
            
            if(last<s[i]) ans--;
            else last=s[i];
        }
        return ans;

    }
};