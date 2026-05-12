class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int len=nums.size();
        vector<vector<int>> v ;
        sort(nums.begin(),nums.end()) ;

        for(int i=0;i<len;i++){
            
            if(i>0 && nums[i]==nums[i-1]) continue ;
            int left = i+1 , right = nums.size()-1 ;
            int localTarget = 0 - nums[i] ; 

            while (left < right) {

                int sum = nums[left] + nums[right];

                if (sum == localTarget) {

                    v.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;

                }

                else if (sum < localTarget) left++;  // ← still needed
                else right--;                         // ← still needed
            }
        }
        return v ; 


        for(int i=0; i<len; i++){
            for(int j=i+1;j<len;j++){

                int target = 0-(nums[i]+nums[j]) ;
                if(binsearch(target,j+1,nums)){
                    if(notFound(nums[i],nums[j],target,v)){
                        vector<int> row = {nums[i],nums[j],target};
                        v.push_back(row) ; 
                    }
                }

            }
        }
        return v;
    }

    bool notFound(int a,int b,int c,vector<vector<int>> &v){
        for(int i=0;i<v.size();i++){
           if(v[i][0]==a && v[i][1]==b && v[i][2]==c)
            return false;
        }
         return true;
    }
    

    bool binsearch(int target, int start , vector<int> &nums){
        int left=start,right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target)return true;
            else if (target<nums[mid]) right=mid-1;
            else left=mid+1;
        }
        return false;
    }

};