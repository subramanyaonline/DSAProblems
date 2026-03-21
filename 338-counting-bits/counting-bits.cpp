class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans={0}; 
        int prevSqno ;
        for(int i=1;i<=n;i++){
            if((i & (i-1)) == 0){
                ans.push_back(1) ; //this is a square number 
                prevSqno = i ; 
            }
            else  ans.push_back(1 + ans[i-prevSqno]) ;
        }
        return ans ;
    }
};