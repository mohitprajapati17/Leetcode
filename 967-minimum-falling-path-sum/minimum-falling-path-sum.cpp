class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int  n=matrix.size();
        int m=matrix[0].size();
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int x=matrix[i][j];
                matrix[i][j]=x+matrix[i-1][j];
                if(j-1>=0) matrix[i][j]=min(matrix[i][j],x+matrix[i-1][j-1]);
                if(j+1<m) matrix[i][j]=min(matrix[i][j],x+matrix[i-1][j+1]);
                
            }
        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int j=0;j<m;j++) mini=min(mini,matrix[n-1][j]);
        return mini;
    }
};