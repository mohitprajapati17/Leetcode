class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int> mpp;
        
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
        }
        int i=1;
        for(auto  & [it,key]:mpp){
            mpp[it]=i;
            i++;
        } 
        vector<int> ans;
        
        for(auto & it:arr){
            ans.push_back(mpp[it]);
        }
        return ans;
    }
};