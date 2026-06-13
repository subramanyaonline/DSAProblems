class Solution {
public:
    bool isMatch(string s, string p) {
        //main twist is s = "ab" , p = ".*"
        //another edge case is when the s="" , p=".* or a*" , ans - true ;

        vector<vector<int>> memo(s.size(),vector<int>(p.size(),-1)) ;
        return recursion(s,p,s.size()-1,p.size()-1,memo) ;
    }

    bool recursion(string &s, string &p, int m, int n, vector<vector<int>> &memo){
        if(m==-1 && n==-1) return true ; 
        if(n==-1) return false ;

        if(m==-1 && p[n]=='*') return recursion(s,p,m,n-2,memo) ;
        else if(m==-1) return false ;
        if(memo[m][n]!=-1) return memo[m][n]; 

        if(p[n]=='*' && p[n-1]=='.'){
            return memo[m][n] = recursion(s,p,m,n-2,memo)||recursion(s,p,m-1,n,memo) /*||recursion(s,p,m-1,n-2,memo)*/ ; 
        }else if(p[n]=='*' && p[n-1]!='.'){
            if(s[m]==p[n-1]){
                return memo[m][n] = recursion(s,p,m-1,n-2,memo)||recursion(s,p,m-1,n,memo) || recursion(s,p,m,n-2,memo);
            }else{
                return memo[m][n] = recursion(s,p,m,n-2,memo) ;
            }
        }else if(p[n]=='.') return memo[m][n] = recursion(s,p,m-1,n-1,memo) ;
        //else  //the last term in both s and p is a alphabet. 
        return memo[m][n] = p[n]==s[m] ? recursion(s,p,m-1,n-1,memo) : false ;     
    }
};