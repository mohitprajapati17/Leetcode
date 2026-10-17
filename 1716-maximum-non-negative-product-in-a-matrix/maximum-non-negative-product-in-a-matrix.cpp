class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int MOD = 1e9 + 7;

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<long long>> maximum(
            n, vector<long long>(m)
        );

        vector<vector<long long>> minimum(
            n, vector<long long>(m)
        );

        maximum[0][0] = grid[0][0];
        minimum[0][0] = grid[0][0];

        for (int i = 1; i < n; i++) {
            maximum[i][0] =
                grid[i][0] * maximum[i - 1][0];

            minimum[i][0] =
                grid[i][0] * minimum[i - 1][0];
        }

        for (int j = 1; j < m; j++) {
            maximum[0][j] =
                grid[0][j] * maximum[0][j - 1];

            minimum[0][j] =
                grid[0][j] * minimum[0][j - 1];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {

                long long a =
                    grid[i][j] * maximum[i - 1][j];

                long long b =
                    grid[i][j] * minimum[i - 1][j];

                long long c =
                    grid[i][j] * maximum[i][j - 1];

                long long d =
                    grid[i][j] * minimum[i][j - 1];

                maximum[i][j] = max({
                    a, b, c, d
                });

                minimum[i][j] = min({
                    a, b, c, d
                });
            }
        }

        long long ans = maximum[n - 1][m - 1];

        if (ans < 0)
            return -1;

        return ans % MOD;
    }
};