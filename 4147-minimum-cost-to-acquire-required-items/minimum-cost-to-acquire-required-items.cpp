class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans=0;
        if(costBoth<cost1+cost2){
            long long mini=min(need1,need2);
            ans+=mini*costBoth;
            need1-=mini;
            need2-=mini;
        }
        
        if(need1){
            if(costBoth<cost1)  ans+=1LL*need1*costBoth;
            else ans+=1LL*need1*cost1;
        }
        
        if(need2){
            if(costBoth<cost2)  ans+=1LL*need2*costBoth;
            else ans+=1LL*need2*cost2;
        }
        
        return ans;
    }
};