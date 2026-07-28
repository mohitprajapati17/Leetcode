class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> hash(26,0);
        for(auto  & it: s){
            hash[it-'a']++;
        }
        cout<<hash[0]<<endl;
        int n=s.size();
        int x=n/2;
        char middle='0';
        for(int i=0;i<26;i++){
            int it=hash[i];
            if(it%2==1){
                middle=i+'a';
            } 
            hash[i]=it/2;
        }
        cout<<middle<<endl;
        string ans="";
        for(int i=0;i<26;i++){
            int it=hash[i];
            while(it--){
                ans+='a'+i;
            }
        }
        string a="";
        a+=ans;

        if(middle!='0') a+=middle;
        reverse(ans.begin(),ans.end());
        a+=ans;

        return a;
    }
};