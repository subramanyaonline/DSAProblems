class Solution {
public:

    int climbStairs(int n) {
        //space optimised dp . 
        int first = 1 ; 
        int second = 1 ; 
        int third = 1; 

        for(int i=2;i<=n;++i){
            third = first + second ; 
            first = second ; 
            second = third ; 
        }
        return third ; 
    }
};