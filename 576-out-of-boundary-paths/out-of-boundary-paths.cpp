class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> prev(m+2,vector<int>(n+2,0)) ; 
        vector<vector<int>> curr(m+2,vector<int>(n+2,0)) ; 
        const int modval = 1e9 + 7 ; 

        for(int i=1;i<=m;++i){
            prev[i][0] = 1 ; 
            prev[i][n+1] = 1; 
        }

        for(int j=1;j<=n;++j){
            prev[0][j] = 1 ; 
            prev[m+1][j] = 1 ; 
        }

        //currently the prev is for maxMoves = 0 . the base case . 

        for(int k = 1 ; k<=maxMove ; ++k){
            for(int i=1;i<=m;++i){ curr[i][0]=1; curr[i][n+1]=1; }
            for(int j=1;j<=n;++j){ curr[0][j]=1; curr[m+1][j]=1; }
            
            for(int i=1; i<=m ; ++i){
                for(int j=1;j<=n; ++j){
                    int moveup = prev[i-1][j] ; 
                    int movedown = prev[i+1][j] ; 
                    int moveleft = prev[i][j-1] ; 
                    int moveright = prev[i][j+1] ;

                    curr[i][j] = 
                    ( (moveup + movedown)%modval + (moveleft + moveright)%modval )%modval ; 
                    cout<<curr[i][j] << " " ;
                }
                cout<<endl ; 
            }
            cout<<endl; 
            prev = curr ; 
        }

        return prev[startRow+1][startColumn+1] ;
    }
};