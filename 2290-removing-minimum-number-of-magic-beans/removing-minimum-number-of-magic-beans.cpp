class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int size = beans.size(); 
        vector<long long> sufSum(beans.size())  ; 

        sort(beans.begin(), beans.end()) ; 

        for(int i=size-2;i>=0;--i){
            sufSum[i] = sufSum[i+1] + beans[i+1] ; 
        }

        long long minCost = 10e11 ; 
        long long leftSum = 0 ; 

        for(int i=0;i<size;i++){
            int rightBags = size-1-i ; 
            //to level all the bags of right side to this height, we have to remove all the heights smaller than this and to the right ,we have to reduce all bags to have this much beans only. 
            long long curCost = leftSum + sufSum[i] - 1LL*beans[i]*rightBags ; 
            minCost = min(minCost,curCost) ; 
            leftSum += beans[i] ; 
        }

        return minCost ; 
    }
};