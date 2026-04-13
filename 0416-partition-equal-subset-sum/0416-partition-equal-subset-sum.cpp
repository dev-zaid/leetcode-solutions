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

        vector<bool> prev(target + 1, 0);
        vector<bool> curr(target + 1, 0);

        prev[0] = curr[0] = true;

        if (nums[0] <= target)
            prev[nums[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= target; j++) {
                bool notTake = prev[j];
                bool take = false;

                if (j >= nums[i]) {
                    take =
                        prev[j - nums[i]];
                }

                curr[j] = take | notTake;
            }

            prev = curr;
        }

        return prev[target];
    }
};