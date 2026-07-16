class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        map<string,int>mpp;
        // mpp[startGene]=1;
        for(auto & it: bank ){
            
            mpp[it]=-1;
        }
        queue<pair<string , int>> q;
        q.push({startGene,0});
        while(!q.empty()){
            string x=q.front().first;
            int cnt=q.front().second;
            cout<<x<<endl;
            q.pop();
            if(mpp[x]==1) continue;
            if(x==endGene)  return cnt;
            mpp[x]=1;


            for(auto & [it,key]:mpp){
                if(key==-1){
                    int c=0;
                    for(int i=0;i<8;i++){
                        if(it[i]!=x[i]) c++;
                    }
                    if(c==1){
                        q.push({it,cnt+1});
                    }
                }
            }
        }
        return -1;

    }
};