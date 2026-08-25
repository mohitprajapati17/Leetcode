class Solution {
public:
    bool isPalindromic(string s) {
        string p="";
        for(auto & it: s){
            int a=it;
            bitset<8> binary(a);
            p+=binary.to_string();
        }
        string x=p;
        reverse(p.begin(),p.end());
        cout<<x<<"  "<<p<<endl;
        if(x==p) return true;
        return false;
        

    }
};