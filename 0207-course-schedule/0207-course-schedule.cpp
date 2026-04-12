class Solution {
public:
    bool isCyclicDFS(int src,vector<bool>& vis, vector<bool>& recPath,vector<vector<int>>& edges){
        vis[src] = true;
        recPath[src] = true;
        for(auto& edge: edges){
            int u = edge[1];
            int v = edge[0];

            if(u==src){
                //neighbour is visited?
                if(!vis[v]){
                    if(isCyclicDFS(v, vis, recPath, edges)){
                        return true;
                    }
                }else if(recPath[v]){
                    return true;
                }
            }
        }
        recPath[src] = false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<bool> vis(n, false);
        vector<bool> recPath(n, false);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(isCyclicDFS(i, vis, recPath, prerequisites)){
                    return false;
                }
            }
        }

        return true;
        
    }
};