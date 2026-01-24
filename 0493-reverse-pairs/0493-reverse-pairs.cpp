class Solution {
public:
    int merge(vector<int>& arr, int start, int mid, int end){
        int count = 0, i=start, j=mid+1;
        for(int i=start; i<=mid; i++){
            while(j<=end && arr[i] > 2LL *arr[j]){
                j++;
            }

            count += j-(mid+1);
        }

        vector<int> temp;
        i=start, j=mid+1;
        while(i<=mid && j<=end){
            if(arr[i] < arr[j]){
                temp.push_back(arr[i]);
                i++;
            }

            else{
                temp.push_back(arr[j]);
                j++;
            }
        }

        while(i<=mid){
            temp.push_back(arr[i]);
            i++;
        }

        while(j<=end){
            temp.push_back(arr[j]);
            j++;
        }

        for(int idx=0; idx<temp.size(); idx++){
            arr[idx+start] = temp[idx];
        }

        return count;
    }

    int mergeSort(vector<int>& arr, int start, int end){
        int inv = 0;
        
        if(start>=end){
            return inv;
        }

        int mid = start + (end-start)/2;
        inv += mergeSort(arr, start, mid);
        inv += mergeSort(arr, mid+1, end);
        inv += merge(arr, start, mid, end);

        return inv;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};