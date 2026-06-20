class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        auto r = restrictions ;
        r.push_back({1,0}); 
        sort(r.begin(),r.end()) ;
        if(r[r.size()-1][0]!=n) r.push_back({n,n-1}); 

        int m = r.size(); 
        for(int i=1;i<m;i++){
            r[i][1] = min(r[i][1] , r[i-1][1]+(r[i][0]-r[i-1][0])); //() to avoid int overflow 
        }

        for(int i=m-2;i>=0;i--){
            r[i][1] = min(r[i][1],r[i+1][1]+(r[i+1][0]-r[i][0])); ;
        }

        int mh = 0 ; //maxheight 
        for(int i=1;i<m;i++){
            int dist = r[i][0]-r[i-1][0] ; 
            int cmh ; //current max height 
            cmh = (dist+r[i][1]+r[i-1][1])/2 ;
            mh = max(cmh,mh) ; 
        }
        return mh ; 
    }
};