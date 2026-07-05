class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diffarr(n+1) ; 

        for(int i=0;i<bookings.size();i++){
            int seat = bookings[i][2] ; 
            int from = bookings[i][0] ; 
            int to = bookings[i][1] ; 
            diffarr[from] = diffarr[from]+seat ; 
            if(to<n) diffarr[to+1] = diffarr[to+1]-seat ; 
        }

        for(int i=1;i<=n;i++){
            diffarr[i] = diffarr[i-1]+diffarr[i] ; 
        }
        return vector<int>(diffarr.begin()+1, diffarr.end()) ; 
    }
};