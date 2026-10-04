class Solution {
public:
    int recurse(int n , vector<int> &cache){
        if(n==0 || n==1) return 1 ; 

        if(cache[n]!=-1) return cache[n] ; 
        return cache[n] = recurse(n-1,cache)+ recurse(n-2,cache) ; 
    }

    int climbStairs(int n) {
        vector<int> cache(n+1,-1) ; 
        cache[0] = 1 ; 
        cache[1] = 1 ; 

        recurse(n,cache) ;
        return cache[n] ; //else you can just return recurse(n,chache) , no need to assign base cases . 
    }
};