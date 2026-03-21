class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> um ;
        for(int ele : nums) {
            if(um.count(ele)) um[ele]++;
            else um[ele]=1;
        }
        for(pair<int,int> p : um) if(p.second ==1 ) return p.first ;
        return 0 ;
    }
};