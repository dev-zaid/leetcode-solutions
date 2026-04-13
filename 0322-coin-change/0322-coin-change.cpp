class Solution {
public:
    int solver(int n, int target, vector<int>& arr, vector<vector<int>>& dp) {
        // Tabulization
        //  base case
        for (int i = 1; i <= target; i++) {
            if (i % arr[0] == 0)
                dp[0][i] = i / arr[0];
            else
                dp[0][i] = 1e9;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < target + 1; j++) {
                int notTake = 0 + dp[i - 1][j];
                int take = 1e9;

                if (j >= arr[i]) {
                    take = 1 + dp[i][j - arr[i]];
                }

                dp[i][j] = min(notTake, take);
            }
        }

        int ans = dp[n - 1][target];
        return ans < 1e9 ? ans : -1;
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        return solver(n, amount, coins, dp);
    }
};