class Solution {
public:
    void solve(vector<int>& nums, int i, vector<int> &ele, vector<vector<int>> &ans){
        if(i==nums.size()){
            ans.push_back(ele);
            return;
        }

        ele.push_back(nums[i]);
        solve(nums, i+1, ele, ans); //include
        ele.pop_back();

        int idx=i+1;
        while(idx<nums.size() && nums[idx]==nums[idx-1]) idx++;
        solve(nums, idx, ele, ans); //exclude
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ele;

        sort(nums.begin(), nums.end());
        solve(nums, 0, ele, ans);

        return ans;
    }
};