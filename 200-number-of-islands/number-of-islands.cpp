class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size())) ;
        int noOfIslands = 0 ;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    dfs(grid,i,j,visited) ;
                    noOfIslands++ ;
                }
            }
        }
        return noOfIslands ;
    }

    void dfs(vector<vector<char>> &grid, int i, int j , vector<vector<bool>> &visited ){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||visited[i][j]||grid[i][j]=='0') return ;
        visited[i][j] = true ;
        dfs(grid,i+1,j,visited) ;
        dfs(grid,i-1,j,visited) ;
        dfs(grid,i,j+1,visited) ;
        dfs(grid,i,j-1,visited) ;
    }
};