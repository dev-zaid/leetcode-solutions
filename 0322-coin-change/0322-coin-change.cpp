class Solution {
public:
    int solver(int idx, int target, vector<int>& arr, vector<vector<int>> &dp){
        if(target == 0) return 0;
        if(idx == 0){
            if(target % arr[idx] == 0) return target/arr[idx];
            else return 1e9;
        };

        if(dp[idx][target] != -1) return dp[idx][target];


        int notTake = 0 + solver(idx-1, target, arr, dp);
        int take = 1e9;

        if(target >= arr[idx]){
            take = 1 + solver(idx, target - arr[idx], arr, dp);
        }

        return dp[idx][target] = min(notTake, take);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = solver(n-1, amount, coins, dp);


        return ans < 1e9 ? ans : -1;
    }
};