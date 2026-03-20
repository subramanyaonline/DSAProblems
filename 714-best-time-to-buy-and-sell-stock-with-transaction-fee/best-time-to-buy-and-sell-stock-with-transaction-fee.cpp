class Solution {
public:
    int maxProfit(vector<int>& nums, int fee) {
        int holding = -nums[0];
        int notHolding = 0 ;
        // i will be charging the fee after selling the stock not after buying , because at last i need not holding value, 
        for(int i=1;i<nums.size() ; i++){
            int temp = max(holding, notHolding - nums[i]);
            notHolding = max(notHolding,holding + nums[i]-fee);
            holding = temp ;
        }
        return notHolding ;
    }
};