class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end()) ; 

        int removed = 0 ; 
        int prevEnd = intervals[0][1] ; 

        for(int i=1;i<intervals.size();++i){
            int curstart = intervals[i][0] ; 
            int curend = intervals[i][1] ; 

            if(curstart<prevEnd){// intervals are overlapping 
                removed++ ; 
                prevEnd = min(curend,prevEnd) ; 
            }else{
                prevEnd = curend ; 
            }
        }

        return removed ; 
    }
};