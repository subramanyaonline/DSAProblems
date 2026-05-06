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
        return recursion(s,s.size(),dp);
    






        // vector<int> dp(s.size()+1) ;
        // //dp[i] = no of ways to decode string till i ;
        // dp[0] = s[0]!='0' ? 1 : 0 ;     //base case 
        // for(int i=1;i<s.size();i++){
        //     if(dp[i-1]==0) return 0 ;
        //     if(s[i]=='0'){
        //         if(s[i-1]=='2' || s[i-1]=='1' ) dp[i]=dp[i-1]-1 ;               
        //         else dp[i]=0 ;
        //         if(i==1) dp[i] = dp[i]+1 ;
        //     }
        //     else{
        //         int curno = s[i] - '0';
        //         int prevno = s[i-1] - '0';
        //         if (prevno==0) dp[i]=dp[i-1] ;
        //         else if(prevno==1) dp[i]=dp[i-1]+1 ;
        //         else if(prevno==2 && curno<7) dp[i]=dp[i-1]+1;
        //         else dp[i]=dp[i-1] ;
        //     }
        // }
        // return dp[s.size()-1];
    }
};