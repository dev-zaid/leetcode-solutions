class Solution {
public:

    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (auto& i : nums)
            totalSum += i;

        if (totalSum % 2 != 0)
            return false;

        int n = nums.size();
        int target = totalSum / 2;

        vector<vector<bool>> dp(n, vector<bool>(target + 1, 0));

        for (int i = 0; i < n; i++)
            dp[i][0] = true; // target = 0;
        if (nums[0] <= target)
            dp[0][nums[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= target; j++) {
                bool notTake = dp[i - 1][j];
                bool take = false;

                if (j >= nums[i]) {
                    take =
                        dp[i - 1][j - nums[i]];
                }

                dp[i][j] = take | notTake;
            }
        }

        return dp[n - 1][target];
    }
};