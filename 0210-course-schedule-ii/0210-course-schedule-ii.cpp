class Solution {
public:
    bool isCyclicDFS(int src, vector<bool>& vis, vector<bool>& recPath,
                     vector<vector<int>>& adj) {
        vis[src] = true;
        recPath[src] = true;

        for (int v : adj[src]) {
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

    void topoSort(int src, vector<bool>& vis, vector<vector<int>>& adj,
                  stack<int>& s) {
        vis[src] = true;

        for (int v : adj[src]) {
            if (!vis[v]) {
                topoSort(v, vis, adj, s);
            }
        }
        s.push(src);
    }

    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n);
        vector<bool> recPath(n);

        for (vector<int>& it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        // check cyclic
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (isCyclicDFS(i, vis, recPath, adj)) {
                    return {};
                }
            }
        }

        stack<int> s;
        vis.assign(n, false);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                topoSort(i, vis, adj, s);
            }
        }

        vector<int> ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};