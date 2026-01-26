class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            // Skip duplicate values
            if(i>0 && nums[i]==nums[i-1]) continue;

            for(int j=i+1; j<n;){
                int p=j+1, q=n-1;
                long long localTarget = target - (long long)nums[i] - (long long)nums[j];
                while(p<q){
                    long localSum = nums[p]+nums[q];
                    if(localSum == localTarget){
                        ans.push_back({nums[i], nums[j], nums[p++], nums[q--]});
                        while(p<q && nums[p] == nums[p-1]) p++;
                    }else if(localSum<localTarget){
                        p++;
                    }else{
                        q--;
                    }
                }

                j++;
                while(j<n && nums[j]==nums[j-1]) j++;
            }
        }

        return ans;
    }
};