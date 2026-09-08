class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        long long sum=0;
        int n=nums.size();
        for(auto & it:nums) sum+=it;
        long long  first=0;
        for(int i=0;i<nums.size()/2;i++){
           first+=nums[i];
        }
        sum-=first;
        int  l=0;
        int r=n/2;
        int ans=0;
        while(r<n){
            if(first!=sum) ans++;
            cout<<first<<" "<<sum<<endl;
            first-=nums[l];
            first+=nums[r];
            sum-=nums[r];
            sum+=nums[l];
            l++;
            r++;
        }
        // if()
        return ans;
    }
};