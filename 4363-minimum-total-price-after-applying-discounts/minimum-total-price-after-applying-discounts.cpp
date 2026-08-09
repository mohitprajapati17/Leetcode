class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        double ans=0;
        
        // int i=0;
        int  n=prices.size();
        int m=discounts.size();
        if(n>m){
        //    int i=n-m;
        //    for(int j=0;j<i;j++) ans+=prices[i];
           sort(prices.rbegin(),prices.rend());
           sort(discounts.rbegin(),discounts.rend());
           for(int i=0;i<n;i++){
            if(i>=m){
                ans+=prices[i];
                continue;
            }
            double x=prices[i]*(100-discounts[i]);
            ans+=x/100;
           }
           
        }
        else{
            sort(prices.rbegin(),prices.rend());
           sort(discounts.rbegin(),discounts.rend());
           for(int i=0;i<n;i++){
            double x=prices[i]*(100-discounts[i]);
            ans+=x/100;
           }
           
        }
        return ans;

    }
};