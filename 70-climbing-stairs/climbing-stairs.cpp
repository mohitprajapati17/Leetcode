class Solution {
public:
    int climbStairs(int n) {
        if(n<=3) return n;
        int p=3,q=2;
        n-=3;
        while(n--){
            int x=p;
            p+=q;
            q=x;
        }
        return p;
    }
};