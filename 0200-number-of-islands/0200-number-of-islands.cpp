class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& vis, int n, int m){
        //base case
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || grid[i][j] != '1') return;

        vis[i][j]=true;
        dfs(i-1,j,grid,vis, n, m);
        dfs(i,j-1,grid,vis, n, m);
        dfs(i+1,j,grid,vis, n, m);
        dfs(i,j+1,grid,vis, n, m);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int islands = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(i,j, grid, vis, n ,m);
                    islands++;
                }
            }
        }

        return islands;
        
    }
};