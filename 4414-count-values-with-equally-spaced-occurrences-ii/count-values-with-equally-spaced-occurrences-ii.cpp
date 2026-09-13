class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int,vector<int>> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]].push_back(i);
        }
        int ans=0;
        for(auto & [it,key]:mpp){
            
            if(key.size()>=3){
                bool flag=true;
                
                int x=key[1]-key[0];
                for(int i=1;i<key.size();i++){
                    if((key[i]-key[i-1])!=x){
                        flag=false;
                        break;
                    }
                }
                if(flag) ans++;
            }
        }
        return ans;
    }
};