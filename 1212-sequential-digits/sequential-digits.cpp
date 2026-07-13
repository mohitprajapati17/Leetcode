class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i=1;i<=9;i++){
            string x="";
            for(int j=i;j<=9;j++){
                x+=j+'0';
                if(stol(x)>=low&&stol(x)<=high){
                    ans.push_back(stol(x));
                }
               
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};