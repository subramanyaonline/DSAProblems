class Solution {
public:
    class DSU{
        public: 
        vector<int> rank ;
        vector<int> parent ; 

        DSU(int n){
            rank.resize(n,0) ; 
            parent.resize(n,0) ; 
            for(int i=0;i<n;i++){
                parent[i] = i ; 
            }
        }

        int find(int u){
            if(parent[u]==u) return u ; 
            return parent[u] = find(parent[u]) ; 
        }

        int unite(int u,int v){
            int root1 = find(u) ; 
            int root2 = find(v) ; 
            if(root1==root2) return false ; 

            if(rank[root1]==rank[root2]){
                parent[root2] = root1 ; 
                rank[root1]++ ; 
            }else if(rank[root1]>rank[root2]){
                parent[root2] = root1 ; 
            }else{
                parent[root1] = root2 ; 
            }
            return true ; 
        }

    }; 

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        DSU dsu(n) ; 
        int i=0,j=1 ; 

        while(j<n){
            while(abs(nums[i]-nums[j])>maxDiff && i<j ){
                i++; 
            }
            dsu.unite(i,j) ; 
            j++ ; 
        }

        vector<bool> ans(queries.size()) ; 
        for(int i=0;i<queries.size();i++){
            int from = queries[i][0] ; 
            int to = queries[i][1] ; 
            if(dsu.parent[from] == dsu.parent[to]) ans[i] = true ;
            else ans[i] = false ; 
        }

        return ans ; 
    }
};