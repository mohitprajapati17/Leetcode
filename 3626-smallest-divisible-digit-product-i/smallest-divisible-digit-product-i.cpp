class Solution {
public:
    int smallestNumber(int n, int t) {
        while(n){
            long long p=1;
            int x=n;
            while(x){
                int d=x%10;
                p=p*d;
                x=x/10;

            }
            if(p%t==0) return  n;

            n++;
        }
        return -1;
    }
};