class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {

        vector<vector<double>> prevdp(n+4,vector<double>(n+4)) ; 
        vector<vector<double>> currdp(n+4,vector<double>(n+4)) ; 
        vector<pair<int,int>> dir = {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}}; 

//base case , which is actually for 0 steps , what is the probability that the knight stays inside the board. which is 100% , ie , 1 probability . 
        for(int i=2;i<=n+1;++i){
            for(int j=2;j<=n+1;++j){
                prevdp[i][j] = 1.0 ; 
            }
        }

        for(int steps = 1 ; steps<=k ;++steps){
            for(int i=2;i<=n+1 ; ++i){
                for(int j=2;j<=n+1;++j){
                    double prob = 0.0 ; 

                    for(auto p : dir){
                        int dx = p.first + i; 
                        int dy = p.second + j; 
                        prob += prevdp[dx][dy] * (double)1/8 ; 
                    }

                    currdp[i][j] = prob ; 
                }
            }
            prevdp = currdp ; 
        }

        return prevdp[row+2][column+2] ; 
    }
};