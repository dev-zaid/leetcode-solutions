class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> ans;

        for(int i=0; i<nums.size(); i++){
            //if found
            if(m.find(target-nums[i]) != m.end()){
                return vector<int> {i, m[target-nums[i]]};
            }

            m[nums[i]] = i;
        }

        return vector<int> {};
    }
};