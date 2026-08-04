class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int odd=0,even=0;
            for(int j=i;j<n;j++){
                if(nums[j]%2==0) even++;
                else odd++;

                if(odd>0){
                    double x=(double)even/odd;
                    double y=(double)a/b;
                    if(x<=y) {
                        
                        ans++;
                    }
                }
            }
        }
        return ans;

    }
};