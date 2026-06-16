class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq ; 
        vector<bool> mst(points.size(),false); 

        int mindistance = 0 ; 
        pq.push({0,0}); //weight,point ... here point is index of the vector points 

        while(pq.size()>0){
            int dist = pq.top().first ;
            int node = pq.top().second ;
            pq.pop(); 
            
            if(!mst[node]){
                mindistance += dist ;
                mst[node] = true ;
                for(int i=0;i<points.size();i++){
                    if(!mst[i]){
                        int dx = abs(points[node][0]-points[i][0]) ;
                        int dy = abs(points[node][1]-points[i][1]) ;
                        pq.push({dx+dy,i}) ;
                    }
                }
            }
        }

        return mindistance ;
    }
};