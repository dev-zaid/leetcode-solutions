class Solution {
public:
    int search(vector<int>& a, int target) {
        int start = 0, end = a.size()-1;

        while(start<=end){
            int mid = start+(end-start)/2;

            if(a[mid] == target){
                return mid;
            }

            if(a[start] <= a[mid]){ // left sorted
                if(a[start] <= target && a[mid] >= target){
                    end = mid-1;
                }
                else{
                    start = mid+1;
                }
            }

            else{ // right sorted
                if(a[end] >= target && a[mid] <= target){
                    start = mid+1;
                }
                else{
                    end = mid-1;
                }
            }
        }

        return -1;
    }
};