class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<vector<int>> soldcount ; 

        for(int i=0;i<mat.size();++i){
            int rowcount = 0 ; 
            for(int j=0;j<mat[0].size();++j){
                if(mat[i][j]==0) break ;
                else rowcount++ ; 
            }
            soldcount.push_back({rowcount,i}) ; 
        }

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq(soldcount.begin(),soldcount.end()) ; 
        vector<int> ans ; 
    
        for(int i=0;i<k;++i){
            ans.push_back(pq.top()[1]) ;
            pq.pop() ;  
        }

        return ans ; 
    }
};