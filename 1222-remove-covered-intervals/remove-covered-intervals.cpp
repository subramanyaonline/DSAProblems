class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] != b[0]) {
        return a[0] < b[0];
        }
        return a[1] > b[1];
        });

        int intervalscount = intervals.size() ; 

        int i = 0 , j=1 ; 
        while(j<intervals.size()){
            if(intervals[i][1]>=intervals[j][1]){
                intervalscount--; 
                j++; 
            }else{
                i=j ; 
                j++; 
            }
        }
        return intervalscount ; 

    }
};