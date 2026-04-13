class Solution {
public:
    bool targetSubarraySum(int idx, int target, vector<int>& arr, vector<vector<int>> &dp){
        if(target==0) return true;
        if(idx == 0){
            return target == arr[0];
        }
        if(dp[idx][target] != -1) return dp[idx][target];

        // idx-1, 
        bool notTake = targetSubarraySum(idx-1, target, arr, dp);

        bool take = false;

        if(target >= arr[idx]){
            take = targetSubarraySum(idx-1, target-arr[idx], arr, dp);
        }

        return dp[idx][target] = take | notTake;
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(auto &i: nums) totalSum += i;

        if(totalSum % 2 != 0) return false;

        int n = nums.size();
        int target = totalSum/2;

        vector<vector<int>> dp(n, vector<int>(target+1, -1));

        return targetSubarraySum(n-1, target, nums, dp);
    }
};