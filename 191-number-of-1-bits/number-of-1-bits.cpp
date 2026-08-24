class Solution {
public:
    int hammingWeight(int N) {
        int count = 0 ; 
        int n = N ; 

        while(n>0){
            if(n&1) count++ ; 
            n = n>>1 ; 
        }

        return count ; 
    }
};