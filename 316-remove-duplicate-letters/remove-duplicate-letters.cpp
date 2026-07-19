class Solution {
public:
    string removeDuplicateLetters(string s) {
        int  n=s.size();
        vector<int>lastIndex(26);
        vector<bool> taken(26,false);
        string ans="";

        for(int i=0;i<n;i++){
            lastIndex[s[i]-'a']=i;
        }

        for(int i=0;i<n;i++){
            char ch=s[i];
            if(taken[ch-'a']==true) continue;
            while(ans.length()>0&&ans.back()>ch&&lastIndex[ans.back()-'a']>i){
                 taken[ans.back()-'a']=false;
                 ans.pop_back();
            }
            ans.push_back(ch);
            taken[ch-'a']=true;

        }

        return ans;
    }
};