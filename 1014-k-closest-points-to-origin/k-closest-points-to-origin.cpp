class Dist{
    public: 
    int index ; 
    int dist ;

    Dist(int i , int d){
        index = i ; 
        dist = d ; 
    }
    bool operator < (const Dist &obj) const {
        return this->dist > obj.dist ; 
    }
};


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<Dist> vec ; 

        for(int i=0;i<points.size();++i){
            int dist = points[i][0]*points[i][0] + points[i][1] * points[i][1] ; 
            vec.push_back(Dist(i,dist)) ; 
        }

        priority_queue<Dist> pq(vec.begin(),vec.end()) ; 
        vector<vector<int>> ans ; 
        for(int i=0;i<k;++i){
            ans.push_back(points[pq.top().index]) ; 
            pq.pop() ; 
        }
        return ans ; 
    }
};