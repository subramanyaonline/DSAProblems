class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size() ; 
        int n = matrix[0].size() ; 

        vector<vector<int>> dp(m,vector<int>(n)) ; 
        int mincost = INT_MAX ; 

        //base case 
        for(int j=0;j<n;j++){
            dp[0][j] = matrix[0][j] ; 
        }

        for(int i=1;i<m;i++){
            dp[i][0] = min(dp[i-1][0] , dp[i-1][1]) + matrix[i][0] ;     
            for(int j=1;j<n-1;j++){
                dp[i][j] = matrix[i][j] + min({dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1]}); 
            }
            dp[i][n-1] = min(dp[i-1][n-1],dp[i-1][n-2]) + matrix[i][n-1] ; 
        }

        for(int j=0;j<n;++j){
            mincost = min(mincost,dp[m-1][j]) ; 
        }
        
        return mincost ; 
    }
};