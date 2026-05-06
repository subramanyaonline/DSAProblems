class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(
            grid.size(), 
            vector<vector<int>> (
                grid[0].size(),vector<int>(1024,-1)
            )
        );

        return recursion(grid,grid.size()-1,grid[0].size()-1,0,dp);
    }

    int recursion(vector<vector<int>> &grid, int m, int n, int curxor, vector<vector<vector<int>>> &dp){
        if(m==0 && n==0) return curxor^grid[m][n] ;
        if(m==0) return recursion(grid,m,n-1,curxor^grid[m][n],dp) ;
        if(n==0) return recursion(grid,m-1,n,curxor^grid[m][n],dp) ;

        if(dp[m][n][curxor] != -1) return dp[m][n][curxor] ;

        return dp[m][n][curxor] = min(recursion(grid,m-1,n,curxor^grid[m][n],dp), recursion(grid,m,n-1,curxor^grid[m][n],dp)) ;
    }
};