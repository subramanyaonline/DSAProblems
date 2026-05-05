class Solution {
public:
    int minAllOneMultiple(int k) {
        if(k%2==0 || k%5==0)return -1;
        string s = to_string(k) ;
        int len = s.size(); 
        int a= 1; 
        int curlen =1 ;
        string curs = "1"; 
        while(curlen<len+1){ //cause for 101 1111 is the start, 
            curs += "1" ;
            curlen++;
            if(stoi(curs)%k == 0) return curlen ; //for 11 and for 111 ..so on 
        }

        int n = stoi(curs) ;
        while(curlen<k+1){
            if(n%k==0)return curlen ;
            curlen++;
            n = (n*10 + 1)%k;
        }

        return -1 ;

    }
};