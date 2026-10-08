class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       stack <int> st;
       int maxA=0;
       int n=heights.size();
       for(int i=0;i<=n;i++){
        while(!st.empty()&&(i==n||heights[st.top()]>=heights[i])){
            int height =heights[st.top()];
            st.pop();
            int width;
            if(st.empty()) width=i;
            else  width=i-st.top()-1;
            maxA=max(maxA,width*height);
        }
        st.push(i);
       }
       return  maxA;

    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int n=matrix.size();
        int m=matrix[0].size();
        int maxarea=0;
       
        vector<vector<int>> prefix(n, vector<int>(m, 0));

        for(int j=0;j<m;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                if (matrix[i][j] == '0') sum = 0;
                else sum += matrix[i][j] - '0';
                prefix[i][j] = sum;

            }

        }
        for(int i=0;i<=n-1;i++){
            maxarea=max(maxarea,largestRectangleArea(prefix[i]));
        }
        return maxarea;
    }
};