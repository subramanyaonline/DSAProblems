class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000) return 0 ;
        string s = to_string(n) ;
        int size = s.size() ;
        long long  prevrange=1, currange ;
        int k = (size-1)/3 ;
        for(int i=0;i<3*k;i++){
            prevrange *= 10 ;
        }
        currange = (n+1-prevrange)*k ;
        return countCommas(prevrange-1) + currange ;
    }
};