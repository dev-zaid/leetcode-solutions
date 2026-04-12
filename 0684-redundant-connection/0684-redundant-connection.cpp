class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int V = edges.size();
        vector<int> parents(V+1);
        for(int i=1; i<=V; i++){
            parents[i]=i;
        }
        
        for(auto &edge: edges){
            int rootU = find(parents, edge[0]);
            int rootV = find(parents, edge[1]);

            if(rootU==rootV) return edge;

            parents[rootU] = rootV;
        }

        return {};
    }

    int find(vector<int> &parents, int i){
        if(parents[i] == i){
            return i;
        }

        return parents[i] = find(parents, parents[i]);
    }
};