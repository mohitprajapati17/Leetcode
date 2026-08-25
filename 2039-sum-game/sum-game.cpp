class Solution {
public:
    bool sumGame(string num) {
      int leftQ=0,rightQ=0;
      int left=0,right=0;
      int n=num.size();
      for(int i=0;i<n;i++){
            if(i<n/2){
                if(num[i]=='?'){
                    leftQ++;
                }
                else left+=num[i]-'0';
            }
            else{
                if(num[i]=='?'){
                    rightQ++;
                }
                else right+=num[i]-'0';
            }
      }
      if((leftQ+rightQ)%2==1&&leftQ!=0&&rightQ!=0){
         return true;
      }
      cout<<2*left+leftQ*9<<endl;
      cout<<2*right+rightQ*9<<endl;
      if((2*left+leftQ*9)==(2*right+rightQ*9))return  false;
      return true;

    }
};