class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> hashset ; 
        int n = nums.size() ; 

        vector<vector<int>> ans ;

        sort(nums.begin(),nums.end()) ; 

        for(int i=0;i<n;++i){
            for(int j=i+1 ; j<n ; ++j){
                long long localTarget = target - (long long)nums[i] - nums[j] ;
                int l = j+1 ; 
                int r = n-1 ; 

                while( l<r ){
                    //cout<<l<<" "<<r <<endl; 
                    long long cursum = (long long)nums[l] + nums[r] ; // cursum
                    if( cursum == localTarget){
                        
                        vector<int> temp = {nums[i],nums[j],nums[l],nums[r]} ; 
                        if(!hashset.contains(temp)) {
                            ans.push_back(temp) ;
                            hashset.insert(temp) ; 
                        } 
                        l++; r-- ; 
                    }else if(cursum < localTarget){
                        l++; 
                        while(l<r && nums[l]==nums[l-1]) l++; 
                    }else{
                        r--; 
                        while(l<r && nums[r]==nums[r+1]) r-- ; 
                        //this extra while loop removes the overhead of keeping a hashset for found ans temp arr. 
                    }
                }

            }
        }

        return ans ; 
    }
};