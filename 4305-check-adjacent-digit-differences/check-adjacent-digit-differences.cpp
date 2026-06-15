class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        for(int i=1;i<s.size();i++){
            if(abs(s[i]-s[i-1])>2) return false ;
        }
        return true ;
        // char first ;
        // char second = s[0] ;
        // for(int i=1;i<s.size();i++){
        //     first = second ;
        //     second = s[i] ; 
        //     if(abs(first-second)>2) return false ;
        // }
        // return true ;
    }
};