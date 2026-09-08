class Solution {
public:
    int minFallingPathSum(vector<vector<int>> &matrix,int m, int n, vector<vector<int>> &memo){
        if(n==0 || n==matrix[0].size()+1) return INT_MAX ; //cause cannot choose a cell out of boundary 
        if(m==0) return 0 ; //base case 

        if(memo[m][n] != INT_MIN) return memo[m][n] ; 

        //teh min path includes current cell
        int cost = matrix[m-1][n-1] + min({minFallingPathSum(matrix,m-1,n-1,memo),minFallingPathSum(matrix,m-1,n,memo) , minFallingPathSum(matrix,m-1,n+1,memo)}) ; 

        memo[m][n] = cost ; 

        //the min path doesnot include the current cell
        return min(cost,minFallingPathSum(matrix,m,n-1,memo)) ; 
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size() ; 
        int n = matrix[0].size() ; 

        vector<vector<int>> memo(m+1,vector<int>(n+1,INT_MIN)) ; 

        int mincost = INT_MAX ;
        for(int colsize = 1 ; colsize<=n ; colsize++){
            mincost = min(mincost,minFallingPathSum(matrix,m,colsize,memo)) ; 
        }
        return mincost ; 
    }
};