class Solution {
public:
    void reverseArray(vector<int>& arr, int start, int end){
        while(start<end){
            swap(arr[start++], arr[end--]);
        }
    }

    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int piv = -1;

        for(int i=n-2; i>=0; i--){
            if(arr[i] < arr[i+1]){
                piv = i;
                break;
            }
        }

        if(piv == -1){
            reverseArray(arr, 0, n-1);
            return;
        }

        // Replace the pivot with the number > pivot
        for(int i=n-1; i>piv; i--){
            if(arr[i]>arr[piv]){
                swap(arr[i], arr[piv]);
                break;
            }
        }

        // Reverse the entire array after the pivot
        reverseArray(arr, piv+1, n-1);
    }
};