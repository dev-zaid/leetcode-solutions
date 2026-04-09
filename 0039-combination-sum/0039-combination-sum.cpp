class Solution {
public:
    set<vector<int>> s;
    void helper(vector<int>& arr, int idx, int target, vector<int> &comb, vector<vector<int>> &ans){
        if(idx == arr.size() || target<0){
            return;
        }

        if(target==0){
            if(s.find(comb) == s.end()){
                ans.push_back(comb);
                s.insert(comb);
            }
            return;
        }

        comb.push_back(arr[idx]);
        helper(arr, idx+1, target-arr[idx], comb, ans); //include single
        helper(arr, idx, target-arr[idx], comb, ans); //include multiple

        comb.pop_back();
        helper(arr, idx+1, target, comb, ans); //dont include
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        helper(candidates, 0, target, comb, ans);
        
        return ans;
    }
};