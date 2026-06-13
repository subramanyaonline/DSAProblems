class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1,false)) ;
        //dp[i][j] = is s with size i and p with size j are matching? if y then t else f
        dp[0][0] = true ;
        //if(s size is k and p size is 0 then flase)
        //if(s size is 0 and p size is more then it depends on *)

        for(int i=2;i<=p.size();i+=2){
            if(p[i-1]=='*') dp[0][i] = true ;
            else break; 
        }

        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=p.size();j++){
                if(p[j-1]=='*' && p[j-2]=='.') dp[i][j] = dp[i-1][j] || dp[i][j-2] ;
                else if(p[j-1]=='*' && p[j-2]!='.'){
                    if(p[j-2]==s[i-1]){
                        dp[i][j] = dp[i-1][j] || dp[i][j-2] ; 
                    }
                    else{dp[i][j] = dp[i][j-2] ; }
                }
                else if(p[j-1]=='.') dp[i][j] = dp[i-1][j-1] ;
                else dp[i][j] = p[j-1]==s[i-1] ? dp[i-1][j-1] : false ;
            }
        }
        return dp[s.size()][p.size()] ; 
    }
};