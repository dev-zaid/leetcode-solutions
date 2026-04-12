class Solution {
public:
    bool isCyclicDFS(int src, vector<bool>& vis, vector<bool>& recPath,
                     vector<vector<int>>& adj) {
        vis[src] = true;
        recPath[src] = true;
        for (int v : adj[src]) {
            // neighbour is visited?
            if (!vis[v]) {
                if (isCyclicDFS(v, vis, recPath, adj)) {
                    return true;
                }
            } else if (recPath[v]) {
                return true;
            }
        }
        recPath[src] = false;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<bool> vis(n, false);
        vector<bool> recPath(n, false);

        vector<vector<int>> adj(n);
        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }
        
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (isCyclicDFS(i, vis, recPath, adj)) {
                    return false;
                }
            }
        }

        return true;
    }
};