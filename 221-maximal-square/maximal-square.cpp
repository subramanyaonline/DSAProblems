class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i=0;i<matrix.size();i++) dp[i][0] = matrix[i][0]=='1' ? 1 : 0 ;
        for(int i=0;i<matrix[0].size();i++) dp[0][i] = matrix[0][i]=='1'?1:0;

        //dp[i][j] = len of max square possible ending at that index i, j ;
        int maxsqlen = 0 ;

        for(int i=1;i<dp.size();i++){
            for(int j=1;j<dp[0].size();j++){
                if(matrix[i][j]=='0') continue ; //it is 0 by default 

                int left = matrix[i][j-1] - '0' ;
                int up = matrix[i-1][j] - '0' ;
                if(left&&up == 0 ){
                    dp[i][j]=1;
                    continue ;
                }

                left = dp[i][j-1];
                up = dp[i-1][j];
                int minn = min(left,up) ;
                if(matrix[i-minn][j-minn]=='0'){
                    dp[i][j] = minn ;
                    continue ;
                }
                dp[i][j]=minn+1 ;
            }
        }

        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[0].size();j++){
                maxsqlen = max(maxsqlen,dp[i][j]) ;
            }
        }
            
        return maxsqlen*maxsqlen ;
    }
};