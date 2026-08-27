class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //applying greedy solution here of activity selection 
        sort(intervals.begin(),intervals.end(),[](vector<int> &a,vector<int> &b)->bool{
           return  a[1]<b[1];
        });
        int totalactivity=0 , currenttime=INT_MIN;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]>=currenttime){ //checking if the start index is less than current time
                totalactivity++;
                currenttime=intervals[i][1];
            }
        }
        //total activity gives the maximum number of activies possible without overlapping
        return intervals.size()-totalactivity; //gives how many activities are overlapping
    }
};