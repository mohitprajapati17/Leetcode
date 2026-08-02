class Solution {
public:
    int dp(int l,int r,vector<int>&piles){

    if(l==r)
        return piles[l];

    int takeLeft = piles[l] - dp(l+1,r,piles);

    int takeRight = piles[r] - dp(l,r-1,piles);

    return max(takeLeft,takeRight);
}

    bool stoneGame(vector<int>& piles) {
        return true;
    }
};