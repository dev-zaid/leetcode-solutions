class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxAr = INT_MIN, lp=0, rp=height.size()-1;

        while(lp < rp){
            int width = rp-lp;
            int h = min(height[lp], height[rp]);
            maxAr = max(maxAr, h*width);

            height[lp] < height[rp] ? lp++ : rp--;
        }

        return maxAr;
    }
};