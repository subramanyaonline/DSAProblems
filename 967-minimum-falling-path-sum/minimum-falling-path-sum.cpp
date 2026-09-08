class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size() ; 
        int n = matrix[0].size() ; 

        vector<int> prevdp(n) ; 
        vector<int> currdp(n) ; 

        int mincost = INT_MAX ; 

        //base case 
        for(int j=0;j<n;j++){
            prevdp[j] = matrix[0][j] ; 
        }

        for(int i=1;i<m;i++){
            currdp[0] = min(prevdp[0] , prevdp[1]) + matrix[i][0] ;     

            for(int j=1;j<n-1;j++){
                currdp[j] = matrix[i][j] + min({prevdp[j-1],prevdp[j],prevdp[j+1]}); 
            }
            
            currdp[n-1] = min(prevdp[n-1],prevdp[n-2]) + matrix[i][n-1] ; 

            prevdp = currdp ; 
        }

        for(int j=0;j<n;++j){
            mincost = min(mincost,prevdp[j]) ; 
        }

        return mincost ; 
    }
};