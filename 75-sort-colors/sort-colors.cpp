class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count(3) ; 

        for(int i=0;i<nums.size();++i){
            count[nums[i]]++ ; 
        }

        int j = 0 ; 
        for(int i=0;i<count.size();++i){
            for(int k=0;k<count[i];k++,j++){
                nums[j] = i ; 
            }
        }

    }
};