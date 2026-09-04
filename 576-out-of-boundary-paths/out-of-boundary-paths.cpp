class Solution {
public:
    const int modval = 1e9 + 7 ; 
    int recurse(int m , int n , int maxMove , int i , int j, vector<vector<vector<int>>> &memo){

        if((i<0 || i>=m || j<0 || j>=n) && maxMove >= 0 ) return 1 ; 
        else if((i<0 || i>=m || j<0 || j>=n) || maxMove < 0) return 0 ;

        //cout<<i<<" "<<j <<" "<<maxMove<< endl ; 
        if(memo[i][j][maxMove] != -1) return memo[i][j][maxMove] ; 

        int down = recurse(m,n,maxMove-1,i+1,j,memo) % modval ; 
        int up = recurse(m,n,maxMove-1,i-1,j,memo) % modval ; 
        int right = recurse(m,n,maxMove-1,i,j+1,memo) % modval ; 
        int left = recurse(m,n,maxMove-1,i,j-1,memo) % modval ; 

        return memo[i][j][maxMove] = 
        ( (down+up)%modval + (right+left)%modval ) % modval ; 
     
    }


    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> memo(m,
            vector<vector<int>>(n,
                vector<int>(maxMove+1,-1)
            )
        ); 

        return recurse(m,n,maxMove,startRow,startColumn,memo) ; 
    }
};