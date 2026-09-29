class Solution {
public:
    int rec(int i,int j,string s1,string s2,vector<vector<int>>& dp){


        // insert
        if(j>=s2.size()) return s1.size()-i;
        if(i>=s1.size()) return s2.size()-j;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]!=s2[j]){
            return dp[i][j]=min(1+rec(i,j+1,s1,s2,dp),min(1+ rec(i+1,j+1,s1,s2,dp),1+rec(i+1,j,s1,s2,dp)));
        }
        else return  dp[i][j]=rec(i+1,j+1,s1,s2,dp);
        
    }
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return rec(0,0,word1,word2,dp);
    }
};