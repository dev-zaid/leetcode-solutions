class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int st = 0;
        int end = nums.size()-1;
        int mid;

        if(target > nums[end]){
            return end+1;
        }

        while(st <= end){
            mid = st+(end-st)/2;

            if(nums[mid] == target){
                return mid;
            }

            if(target < nums[mid]){
                end = mid-1;
            } else{
                st = mid + 1;
            }
        }

        return st;
    }
};