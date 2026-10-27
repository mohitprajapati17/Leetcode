class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans(m);
        for(int i=0;i<m;i++){

            if(i==0){
                string x="";
                for(int j=0;j<n;j++) x+='.';
                ans[i]=x;
                
            }
            else{

                string x="";
                for(int  j=0;j<n-1;j++) x+='#';
                x+='.';
                ans[i]=x;
            }
        }
        return ans;
    }
};