class Solution {
public:
    int numberOfSubstrings(string s) {
        int len = s.size() ;
        int lastOccurance[3] = {-1,-1,-1}  ;
        int count = 0 ; 

        //we are couting every valid substring ending at i.
        for(int i=0;i<len;i++){
            lastOccurance[s[i]-'a'] = i ; 

            int startPoint = 1e5; 
            for(int j=0;j<3;j++){
                startPoint = min(startPoint,lastOccurance[j]) ; 
            }
            if(startPoint<0) continue ; 
            count += startPoint+1 ; 
        }
        return count ; 
    }
};