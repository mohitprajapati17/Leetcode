class Solution {
public:
    vector<string> largestString(vector<int>& nums){
        vector<int> a = { 1,
                                                    2,
                                                    4,
                                                    8,
                                                    16,
                                                    32,
                                                    64,
                                                    128,
                                                    256,
                                                    512,
                                                    1024,
                                                    2048,
                                                    4096,
                                                    8192,
                                                    16384,
                                                    32768,
                                                    65536,
                                                    131072,
                                                    262144,
                                                    524288,
                                                    1048576,
                                                    2097152,
                                                    4194304,
                                                    8388608,
                                                    16777216,
                                                    33554432,
                                                    67108864,134217728};

    vector<string> ans;
    for(auto & it: nums){
        string s="";
        while(it){
            int y=upper_bound(a.begin(),a.end(),it)-a.begin();
            y--;
            // cout<<y<<endl;
            int x=y;
            if(x==26) s+="zz";
            else s+='a'+x;
            
            it-=a[x];

        }
        ans.push_back(s);
    }
    return  ans;
}
}
;