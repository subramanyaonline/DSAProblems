class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        int n = 0 ; 
        for(int i=0;i<trips.size();i++) n = max(n,trips[i][2]);
        vector<int> diffarr(n+1) ; 

        for(const auto & trip : trips ){
            int from = trip[1]; 
            int to = trip[2] ; 
            int passengers = trip[0] ; 
            diffarr[from] = diffarr[from] + passengers ; 
            diffarr[to] = diffarr[to] - passengers ; 
        }

        int curMemInCar = diffarr[0] ;
        if(curMemInCar>capacity) return false ;  
        for(int i=1;i<=n;i++){
            diffarr[i] = diffarr[i] + diffarr[i-1] ; 
            if(diffarr[i]>capacity) return false  ; 
        }

        return true ; 
    }
};