class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        //99,100,1    011. 
        
        int left = 0 ,right=0; 
        long long sum =0 ;
        while(left<nums.size() && s[left]=='1') {
            sum += nums[left]; 
            left++; 
        }

        while(left<nums.size()-1){

            right = left+1 ;
            int minval = nums[left] ;
            sum+= nums[left] ;
            while(right<nums.size() && s[right]=='1'){
                minval = min(minval,nums[right]);
                sum += nums[right] ;
                right++;
            }
            sum -= minval ; 
            left = right ;
        }
        return sum ;
    }
};