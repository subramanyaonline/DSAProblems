class Solution {
public:
    int recursion(string &s, int n /*size*/,vector<int> &dp){
        if(n==0) return 1 ;
        if(n==1 && s[n-1]=='0') return 0 ; 
        else if(n==1) return 1 ;

        if(dp[n] != -1) return dp[n] ;

        int a = 0; 
        int b = 0;
        if(s[n-1]!='0'){ a = recursion(s,n-1,dp); }
        if(s[n-2]=='1'){ b = recursion(s,n-2,dp) ; }
        else if(s[n-2]=='2' && s[n-1]>='0' && s[n-1]<='6'){
            b = recursion(s,n-2,dp) ;
        }
        //else no no possibility ,
        return dp[n] = a+b ;
    }

    int numDecodings(string s) {
        vector<int> dp(s.size()+1,-1) ;
        //return recursion(s,s.size(),dp);

        //dp[i] = possible ways to decode s of size i . 
        dp[0] = 1 ;
        dp[1] = s[0]=='0' ? 0 : 1 ;
        for(int i=2;i<=s.size();i++){
            int a = 0, b= 0 ;
            if(s[i-1]!='0') a = dp[i-1] ;
            if(s[i-2]=='1') b = dp[i-2] ;
            else if(s[i-2]=='2' && s[i-1]>='0' && s[i-1]<='6') b = dp[i-2] ;
            dp[i] = a + b ;
        }
        return dp[s.size()] ;
    }
};