class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxele = 0 ; 
        int sum = 0 ; 
        for(int i=0;i<weights.size();i++){
            maxele = max(maxele,weights[i]) ; 
            sum += weights[i] ; 
        }

        int left = maxele ;  
        int right = sum ; 

        while(left<right){
            int mid = (left + right)/2 ; 
            int D = 1 ; 
            int daysum = 0 ; 

            for(int i=0;i<weights.size();i++){
                daysum += weights[i] ; 
                if(daysum>mid){
                    D++; 
                    daysum = weights[i] ; 
                }
                //if(D>days) break ;                
            }

            if(D>days) left = mid+1 ; 
            else right = mid ; 
        }
        return left ; 
    }
};