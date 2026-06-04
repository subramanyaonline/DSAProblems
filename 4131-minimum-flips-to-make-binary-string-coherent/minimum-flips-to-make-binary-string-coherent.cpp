class Solution {
public:
    int minFlips(string s) {
        if(s.size()<3) return 0 ;
        //i will  count of 0 and 1 . 

        int ones = 0 , zeros = 0 ;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') zeros++;
            else ones++ ;
        }

        if(zeros==0) return 0 ; 
        else if(ones<=1) return 0 ;
        else if(s[0]=='1' && s[s.size()-1]=='1') return min(zeros,ones-2) ; 
        else return min(zeros,ones-1) ;

        return min(zeros,ones-1) ;
    }
};