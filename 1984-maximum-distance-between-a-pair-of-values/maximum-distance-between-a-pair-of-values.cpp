class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int  r1=n1-1,r2=n2-1;
        int ans=0;
        while(r1>=0&&r2>=0){
            if(nums1[r1]<=nums2[r2]){
                if(r1<=r2) ans=max(ans,r2-r1);
            }
            else{
                while(r2>=0&&nums1[r1]>nums2[r2]){
                    r2--;
                }
                if(r1<=r2) ans=max(ans,r2-r1);
            }
            r1--;
        }
        return ans;
    }
};