class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        // Sort the intervals based on the first element of the internal vectors
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[0]<b[0];
        });

        vector<vector<int>> ans;

        vector<int> prev = intervals[0];

        for(int i=1; i<intervals.size(); i++){
            vector<int> currentInterval = intervals[i];

            if(prev[1] >= currentInterval[0]) {
                prev[1] = max(prev[1], currentInterval[1]);
            } else{
                ans.push_back(prev);
                prev = currentInterval;
            }
        }

        ans.push_back(prev);
        return ans;
    }
};