class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size() ; 
        int n = obstacleGrid[0].size() ; 

        vector<int> prevdp(n) ; 
        vector<int> currdp(n) ; 

    //base case 
        for(int j=0;j<n;++j){
            if(!obstacleGrid[0][j]) prevdp[j] = 1 ; 
            else break ; 
        }

        for(int i=1;i<m;++i){
            if(obstacleGrid[i][0]) currdp[0] = 0 ; 
            else currdp[0] = prevdp[0] ; 

            for(int j=1;j<n;++j){
                if(!obstacleGrid[i][j])currdp[j] = currdp[j-1] + prevdp[j] ; 
                else currdp[j] = 0 ; 
            }

            prevdp = currdp ; 
        }

        return prevdp[n-1] ; 
    }
};