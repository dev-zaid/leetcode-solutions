class Solution {
public:
    int trap(vector<int>& arr) {
        int l=0, r=arr.size()-1, lmax=0, rmax=0, ans=0;

        while(l<=r){
            lmax=max(lmax, arr[l]);
            rmax=max(rmax, arr[r]);

            if(lmax<rmax){
                ans += lmax-arr[l++];
            }

            else{
                ans += rmax-arr[r--];
            }
        }

        return ans;
    }
};