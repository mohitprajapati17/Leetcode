class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(9*num<sum) return "";
        string x="";
        while(sum){
           if(sum>9){
            sum-=9;
            x+='9';
           }
           else{
            x+=to_string(sum);
            sum=0;
           }
           num--;
        }
        while(num--) x+='0';
        return  x;
        
    }
};