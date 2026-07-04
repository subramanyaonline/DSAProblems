class Solution {
public:
    class DSU {
        vector<int> parent ; 
        vector<int> rank ; 
        public : 
        DSU(int n){
            parent.resize(n+1,0) ; 
            for(int i=0;i<=n;i++) parent[i] = i ; 
            rank.resize(n+1,0) ; 
        }
        int find(int u ){
            if(parent[u]==u) return u ; 
            return parent[u] = find(parent[u]) ; 
        }
        bool unite(int u , int v ){
            int root1 = find(u) ; 
            int root2 = find(v) ; 
            if(root1==root2) return false ; 
            if(rank[u]==rank[v]){
                rank[root1]++ ; 
                parent[root2] = root1 ; 
            }else if(rank[u]>rank[v]){
                parent[root2] = root1 ; 
            }else {
                parent[root1] = root2 ; 
            }
            return true ; 
        }
    }; 

    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> minEdge(n+1,1e4+1) ; 
        DSU dsu(n) ; 
        for(auto& road : roads){
            int u = road[0];  
            int v = road[1] ; 
            int d = road[2] ; 
            dsu.unite(u,v) ; 
            minEdge[u] = minEdge[v] = min(minEdge[u],min(minEdge[v],d)) ; 
        }

        int globalMin = INT_MAX ; 
        for(int i=1;i<n+1;i++){
            if(dsu.find(i) == dsu.find(n)) globalMin = min(globalMin,minEdge[i]) ; 
        }

        return globalMin ; 
    }
};