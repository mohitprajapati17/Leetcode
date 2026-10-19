class Solution {
public:

    const int MOD = 1e9 + 7;

    int getIntFromChar(char ch) {
        return (ch == 'S' || ch == 'E') ? 0 : ch - '0';
    }

    bool isValid(int i, int j, vector<string>& grid) {
        int n = grid.size();

        return i >= 0 && i < n &&
               j >= 0 && j < n &&
               grid[i][j] != 'X';
    }

    pair<int, int> solve(
        int i,
        int j,
        vector<string>& grid,
        vector<vector<pair<int, int>>>& dp
    ) {

        // Reached E
        if (grid[i][j] == 'E') {
            return {0, 1};
        }

        // Already calculated
        if (dp[i][j] != make_pair(-2, -2)) {
            return dp[i][j];
        }

        int bestScore = -1;
        int bestPath = 0;

        // UP
        if (isValid(i - 1, j, grid)) {

            auto [score, path] =
                solve(i - 1, j, grid, dp);

            // score == -1 means NO valid path
            if (score != -1) {

                score += getIntFromChar(grid[i][j]);

                if (score > bestScore) {
                    bestScore = score;
                    bestPath = path;
                }
                else if (score == bestScore) {
                    bestPath = (bestPath + path) % MOD;
                }
            }
        }

        // LEFT
        if (isValid(i, j - 1, grid)) {

            auto [score, path] =
                solve(i, j - 1, grid, dp);

            if (score != -1) {

                score += getIntFromChar(grid[i][j]);

                if (score > bestScore) {
                    bestScore = score;
                    bestPath = path;
                }
                else if (score == bestScore) {
                    bestPath = (bestPath + path) % MOD;
                }
            }
        }

        // DIAGONAL
        if (isValid(i - 1, j - 1, grid)) {

            auto [score, path] =
                solve(i - 1, j - 1, grid, dp);

            if (score != -1) {

                score += getIntFromChar(grid[i][j]);

                if (score > bestScore) {
                    bestScore = score;
                    bestPath = path;
                }
                else if (score == bestScore) {
                    bestPath = (bestPath + path) % MOD;
                }
            }
        }

        // No path to E
        if (bestScore == -1) {
            return dp[i][j] = {-1, 0};
        }

        return dp[i][j] = {bestScore, bestPath};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {

        int n = board.size();

        // {-2,-2} = not calculated
        vector<vector<pair<int, int>>> dp(
            n,
            vector<pair<int, int>>(n, {-2, -2})
        );

        auto [score, paths] =
            solve(n - 1, n - 1, board, dp);

        if (score == -1)
            return {0, 0};

        return {score, paths};
    }
};