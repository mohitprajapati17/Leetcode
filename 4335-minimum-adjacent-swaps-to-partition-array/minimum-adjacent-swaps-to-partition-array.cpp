class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int mod=int(1e9+7);
        long long cnt1=0,cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<a) nums[i]=0;
            else if(nums[i]<=b) {
                nums[i]=1;
                cnt1++;
                }
            else{
               nums[i]=2;
               cnt2++;
            } 
        }
        long long ans=0;
        for(int  i=nums.size()-1;i>=0;i--){
            if(nums[i]==2) cnt2--;
            else  if(nums[i]==1){
                ans=(ans+cnt2)%mod;
                cout<<cnt2<<endl;
                cnt1--;
            }
            else ans=(ans+cnt1+cnt2)%mod;
        }

        return  ans;



    }
};