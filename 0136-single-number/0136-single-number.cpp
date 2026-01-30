class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for(int val: nums){
            ans = ans ^ val; // XOR cancels out the same elements
        }

        return ans;
    }
};