class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        //if any 2 elements diff is not divisible by x, then return -1 

        vector<int> nums(grid.size()*grid[0].size()) ;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                nums[i*grid[0].size()+j] = grid[i][j] ;
            }
        }

        sort(nums.begin(),nums.end()) ;
        
        int count = 0 ;
        int medianidx = nums.size()/2 ;

        for(int i=0;i<nums.size();i++){
            if((nums[medianidx]-nums[i])%x==0){
                count+= abs(nums[medianidx]-nums[i])/x ;
            }else{
                return -1 ;
            }
        }

        return count ;
        
    }
};