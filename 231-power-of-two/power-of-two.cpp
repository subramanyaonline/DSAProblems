class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<1) return false ; //if this is not given, this will lead to run time error as, overflow of int , lower bound 2p31-1, overflow. 
        return ((n & (n-1)) == 0) ; 
    }
};