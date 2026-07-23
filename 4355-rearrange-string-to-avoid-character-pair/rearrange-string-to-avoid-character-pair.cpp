class Solution {
public:
    string rearrangeString(string s, char x, char y) {

        string t="";
        
        for(auto & it:s){
            if(it==y) {
                t=y+t;
                
                continue;
            }
            t+=it;
        }

        return t;
    }
};