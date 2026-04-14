class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;

        // store indices
        for (int i = 0; i < tickets.size(); i++) {
            q.push(i);
        }

        int time = 0;

        while (!q.empty()) {
            int idx = q.front();
            q.pop();

            tickets[idx]--;
            time++;

            // if kth person is done → return
            if (idx == k && tickets[idx] == 0) {
                return time;
            }

            // if still has tickets → go back
            if (tickets[idx] > 0) {
                q.push(idx);
            }
        }

        return time;
    }
};