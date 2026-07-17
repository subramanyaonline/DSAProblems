class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        //Understanding the problem 
        //min answer will be the max element in nums, max would be sum of nums. 
        //the moment i saw this question , idk why , but felt like this question can be done using binary search, even though i came here to sovle greedily . 

        int sum , maxele = 0; 
        for(int i=0;i<nums.size();i++){
            maxele = max(maxele,nums[i]) ; 
            sum += nums[i] ; 
        }

        int left = maxele , right = sum ; 

        while(left<right){
            int mid = left + (right-left)/2 ; 
            
            int splits = 1 ; 
            int splitsum = 0 ; 
            for(int i=0;i<nums.size();i++){
                splitsum += nums[i] ; 
                if(splitsum>mid){
                    splitsum = nums[i] ; 
                    splits++ ; 
                }
                if(splits>k) break ;
            }

            if(splits<=k){
                right = mid ; 
            }else {
                left = mid+1 ; 
            }
        }
        return right ; 
    }
};