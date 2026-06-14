class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {

        long long maxsum = 0 ; 

        if(units[0].size()==1){
            int sum = 0 ; 
            for(int i=0;i<units.size();i++){
                maxsum += units[i][0] ; 
            }
            return maxsum ; 
        }

        int globalmin = units[0][0] ; 
        int smallestSecondMin = INT_MAX ; 
        int smallestSecondMinRow = 0 ; 

        for(int i=0;i<units.size();i++){
            int firstmin = units[i][0] ; 
            int firstminidx = 0 ; 
            int secondmin = INT_MAX ;

            for(int j=1;j<units[0].size();j++){
                if(firstmin>=units[i][j]){
                    secondmin = firstmin ; 
                    firstmin = units[i][j] ; 
                    firstminidx = j ;
                }
            }
            for(int j=0;j<units[0].size();j++){ //not from 1, because intmax
                if(j==firstminidx) continue ;
                secondmin = min(units[i][j],secondmin) ;
            }
            maxsum += secondmin ;
            globalmin = min(globalmin,firstmin) ;
            smallestSecondMin = min(smallestSecondMin,secondmin) ; 
        }
        maxsum = maxsum - smallestSecondMin + globalmin ;
        return maxsum ;
    }
};