class Solution {
public:
    void merge(vector<int> &arr, int st, int mid, int end){
        vector<int> temp(end - st + 1);

        int i=st, j=mid+1, k=0;

        while(i<=mid && j<=end){
            if(arr[i] <= arr[j]){
                temp[k++]=arr[i];
                i++;
            }
            else{
                temp[k++]=arr[j];
                j++;
            }
        }

        while(i<=mid){
            temp[k++]=arr[i];
            i++;
        }

        while(j<=end){
            temp[k++]=arr[j];
            j++;
        }

        for(int idx=0; idx<temp.size(); idx++){
            arr[idx+st] = temp[idx];
        }
    }

    void mergeSort(vector<int> &arr, int st, int end){
        if(st<end){
            int mid=st+(end-st)/2;

            mergeSort(arr, st, mid);
            mergeSort(arr, mid+1, end);
            merge(arr, st, mid, end);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int st=0, end=nums.size()-1;
        mergeSort(nums, st, end);

        return nums;
    }
};