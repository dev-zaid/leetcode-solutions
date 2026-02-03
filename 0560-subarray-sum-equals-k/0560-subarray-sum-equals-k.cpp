class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        // Store sum and its frequency in the map
        vector<int> PS(n,0);

        PS[0] = nums[0];
        for(int i=1; i<n; i++){
            PS[i] = PS[i-1] + nums[i]; 
        }

        unordered_map<int,int> freqMap; // PS,freq

        for(int j=0; j<n; j++){
            if(PS[j] == k){
                count++;
            }

            int value = PS[j] - k;

            if(freqMap.find(value) != freqMap.end()){
                count += freqMap[value];
            }

            // PrefixSum does not exist in the nap
            if(freqMap.find(PS[j]) == freqMap.end()){
                // Initialise to zero
                freqMap[PS[j]] = 0;
            }

            // Increment Frequency count
            freqMap[PS[j]] ++;
        }   

        return count;
    }
};