class Solution {
public:
    int minOperations(string s) {
        if(is_sorted(s.begin(),s.end())) return 0;
        if(s.size()==2)  return -1;
        vector<int> hash(26,0);
        char m1='z',m2='a';
        int idx1=-1,idx2=-1;
        for(int i=0;i<s.size();i++){
            // m1=min(m1,s[i]);
            hash[s[i]-'a']++;
            if(m1>s[i]){
                idx1=i;
                m1=s[i];
            }
        }

        for(int i=0;i<s.size();i++){
            if(m2<s[i]){
                m2=s[i];
                idx2=i;
            }
        }

        cout<<m1<<" "<<m2<<endl;
        if(m2==s[0]&&m1==s[s.size()-1]&&hash[m2-'a']==1&&hash[m1-'a']==1 ) return 3;
        if(m1==s[0]||m2==s[s.size()-1]) return 1;
        return 2;
    }
};
