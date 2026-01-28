class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);

        ans[0] = 1;

        // Prefix Product of each index in the answer array
        for(int i=1; i<n; i++){
            ans[i] = ans[i-1] * arr[i-1];
        }

        int suffix = 1;

        // Suffix Product of each index in the answer array
        for(int i=n-1; i>=0; i--){
            ans[i] *= suffix;
            suffix *= arr[i];
        }

        return ans;
    }
};