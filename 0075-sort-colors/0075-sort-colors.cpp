class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> m;

        m[0] = 0;
        m[1] = 0;
        m[2] = 0;

        for(int i=0; i<nums.size(); i++){
            m[nums[i]] += 1;
        }

        fill(nums.begin(), nums.begin()+m[0], 0);
        fill(nums.begin()+m[0], nums.begin()+m[0]+m[1], 1);
        fill(nums.begin()+m[0]+m[1], nums.end(), 2);

    }
};