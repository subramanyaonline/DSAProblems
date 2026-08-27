class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end()) ; 
        int n = intervals.size() ; 
        vector<vector<int>> ans ; 

        int start = intervals[0][0] ; 
        int end = intervals[0][1] ; 

        for(int i=1;i<n;i++){
            int curstart = intervals[i][0] ; 
            int curend = intervals[i][1] ; 

            if(end < curstart){
                ans.push_back({start,end}) ; 
                start = curstart ; 
                end = max(end,curend) ; 
            }else{
                end = max(end,curend) ; 
            }
        }
        ans.push_back({start,end}) ; 

        return ans ; 
    }
};