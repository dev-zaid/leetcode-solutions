class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int n = heights.size();
        
        vector<int> rightSmallest(n, 0);
        vector<int> leftSmallest(n, 0);

        for(int i=n-1; i>=0; i--){
            while(s.size()>0 && heights[s.top()] >= heights[i]){
                s.pop();
            }

            rightSmallest[i] = s.empty() ? n : s.top();

            s.push(i);
        }

        //empty Stack
        while(!s.empty()){
            s.pop();
        }

        for(int i=0; i<n; i++){
            while(s.size()>0 && heights[s.top()] >= heights[i]){
                s.pop();
            }

            leftSmallest[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }  

        int maxArea = INT_MIN;

        for(int i=0; i<n; i++){
            int width = rightSmallest[i] - leftSmallest[i] - 1;
            int currArea = heights[i]*width;
            maxArea = max(maxArea, currArea);
        }

        return maxArea;

    }
};