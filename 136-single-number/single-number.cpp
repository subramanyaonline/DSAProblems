class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum = 0 ;
        for(int ele : nums) sum = sum^ele ;
        return sum ;
    }
};