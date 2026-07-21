class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<double,int>> vec(points.size()) ; 

        for(int i=0;i<points.size();i++){
            int x = points[i][0] ; 
            int y = points[i][1] ; 
            double dist = sqrt(x*x + y*y) ; 
            int index = i ; 
            vec[i] = {dist,index} ; 
        }

        sort(vec.begin(),vec.end()) ; 

        vector<vector<int>> ans ; 
        for(int i=0;i<k;i++){
            int index = vec[i].second ; //index of pairs in original array
            ans.push_back(points[index]) ; 
        }

        return ans ; 
    }
};