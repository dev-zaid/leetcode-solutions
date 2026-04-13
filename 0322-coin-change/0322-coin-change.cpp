class Solution {
public:
    int solver(int n, int target, vector<int>& arr, vector<int>& prev, vector<int>& curr) {
        // Tabulization
        //  base case
        for (int i = 1; i <= target; i++) {
            if (i % arr[0] == 0)
                prev[i] = i / arr[0];
            else
                prev[i] = 1e9;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < target + 1; j++) {
                int notTake = 0 + prev[j];
                int take = 1e9;

                if (j >= arr[i]) {
                    take = 1 + curr[j - arr[i]];
                }

                curr[j] = min(notTake, take);
            }

            prev = curr;
        }

        int ans = prev[target];
        return ans < 1e9 ? ans : -1;
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<int> prev(amount + 1, 0);
        vector<int> curr(amount + 1, 0);

        return solver(n, amount, coins, prev, curr);
    }
};