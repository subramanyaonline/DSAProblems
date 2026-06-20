class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& arr) {
        vector<vector<int>> restrictions ; 
        restrictions.push_back({1,0}) ; 
        restrictions.insert(restrictions.end(),arr.begin(),arr.end()) ; 

        // sort(restrictions.begin(),restrictions.end(),[](const vector<int> &a, const vector<int> &b){return a[0]>b[0];}) ;
        //sort(restrictions.begin(),restrictions.end()) ; 
        sort(restrictions.begin(), restrictions.end(), [](const vector<int> &a, const vector<int> &b) {
    return a[0] < b[0];
});

        if(restrictions[restrictions.size()-1][0]!=n){
            restrictions.push_back({n,n-1}) ;
        }

        // for(int i=0;i<restrictions.size();i++){
        //     cout<<restrictions[i][1]<<" "; 
        // }
        //cout<<endl;

        for(int i=1;i<restrictions.size();i++){
            int curheight = restrictions[i][1]; 
            int prevheight = restrictions[i-1][1] ; 
            int curidx = restrictions[i][0] ; 
            int previdx = restrictions[i-1][0] ; 
            if( curheight-prevheight > curidx - previdx){
                restrictions[i][1] = prevheight + curidx - previdx ;
            }
        }

        // for(int i=0;i<restrictions.size();i++){
        //     cout<<restrictions[i][1]<<" "; 
        // }
        // cout<<endl ;

        for(int i=restrictions.size()-2;i>=0;i--){
            int curheight = restrictions[i][1]; 
            int prevheight = restrictions[i+1][1] ; 
            int curidx = restrictions[i][0] ; 
            int previdx = restrictions[i+1][0] ; 
            if(curheight-prevheight > previdx-curidx){
                restrictions[i][1] = prevheight + previdx - curidx  ;
            }
        }

        // for(int i=0;i<restrictions.size();i++){
        //     cout<<restrictions[i][1]<<" "; 
        // }

        int globalmaxheight = 0 ; 
        for(int i=1;i<restrictions.size();i++){
            int curheight = restrictions[i][1]; 
            int prevheight = restrictions[i-1][1] ; 
            int curidx = restrictions[i][0] ; 
            int previdx = restrictions[i-1][0] ; 

            //extra  = dist - diff / 2 ; extra + max of two bars = max height 

            int maxbarheight = max(restrictions[i][1],restrictions[i-1][1]); 
            int minbarheight = min(restrictions[i][1],restrictions[i-1][1]); 

            int dist = abs(restrictions[i][0]-restrictions[i-1][0]) ; 
            int diff = maxbarheight - minbarheight ; 
            int extra = (dist - diff ) / 2; 
            globalmaxheight = max(globalmaxheight, maxbarheight + extra) ;

        }

        return globalmaxheight ; 
    }
};