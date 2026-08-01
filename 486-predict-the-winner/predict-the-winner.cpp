class Solution {
public:
    bool dp(vector<int> &nums  , int  left ,int right, int first, int second ,bool turn){
        if (left > right)
            return first >= second;
        if(turn){
             return (dp(nums,left+1,right,first+nums[left],second,!turn)||dp(nums,left,right-1,first+nums[right],second,!turn));
        }
        else{
            return (dp(nums,left+1,right,first,second+nums[left],!turn)&&dp(nums,left,right-1,first,second+nums[right],!turn));

        }
        return 0;
        
    }
    bool predictTheWinner(vector<int>& nums) {
        return dp(nums,0,nums.size()-1,0,0,true);
    }
};