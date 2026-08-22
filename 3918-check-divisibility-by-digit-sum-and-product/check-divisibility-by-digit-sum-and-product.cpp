class Solution {
public:
    bool checkDivisibility(int n) {
        int  mul=1,sum=0;
        int n1=n;
        while(n1){
            sum+=n1%10;
            mul*=n1%10;
            n1/=10;
        }
        if(n%(mul+sum)==0) return true;
        return false;
    }
};