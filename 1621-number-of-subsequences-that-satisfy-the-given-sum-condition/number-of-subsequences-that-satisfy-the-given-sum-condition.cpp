class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        
        const int mod = 1e9 + 7 ; 
        int len = nums.size() ; 
        sort(nums.begin(),nums.end()) ; 
        int left = 0 , right = len-1 ; 
        int count = 0 ; 

        int* power = new int[len] ; power[0]= 1 ; 
        for(int i=1;i<len;i++){
            power[i] = (power[i-1]*2) %mod; //no need to use ll because mod*2, doesnot overflow. 
        }

        while(right>=left){
            if(nums[right]+nums[left]<=target){
                count += power[right-left] ; 
                count = count % mod ; 
                left++ ; 
            }else{
                right--;
            }
        }
        
        return count ;
    }
};