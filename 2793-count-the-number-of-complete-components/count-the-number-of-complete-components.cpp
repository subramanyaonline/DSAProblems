class Solution {
public:
    class DSU {
    public: 
        vector<int> size; 
        vector<int> parent ; 
    
        DSU(int n){
            size.resize(n,1) ; 
            parent.resize(n,0) ; 
            for(int i=0;i<n;i++) parent[i] = i ; 
        }

        int find(int node){  //name should be findRoot 
            if(parent[node]==node) return node ; 
            return parent[node] = find(parent[node]) ; 
        }
    
        bool unite(int u,int v){
            int root1 = find(u) ; 
            int root2 = find(v) ; 
            if(root1==root2) return false ; 

            if(size[root1]>=size[root2]) {
                size[root1] += size[root2]; 
                parent[root2] = root1 ; 
            }else{
                parent[root1] = root2 ; 
                size[root2] += size[root1] ; 
            }
            return true ; 
        }
    }; 

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n) ; 
        vector<int> edgesPerNode(n) ; 
        int count = 0 ; 

        for(int i=0;i<edges.size();++i){
            int to = edges[i][1] ; 
            int from = edges[i][0] ; 
            edgesPerNode[from]++ ; 
            edgesPerNode[to]++ ; 
            dsu.unite(from,to) ; 
        }

        unordered_map<int,bool> um ;

        for(int i=0;i<n;i++){
            int u = i ; 
            int root = dsu.find(u) ; 
            if(dsu.size[root] == edgesPerNode[u]+1){
                if(!um.count(root)) um[root] = true ; 
            }else{
                um[root] = false ; 
            }      
        }

        for(auto p : um){
            if(um[p.first]) count++; 
        }

        return count ; 
    }
};