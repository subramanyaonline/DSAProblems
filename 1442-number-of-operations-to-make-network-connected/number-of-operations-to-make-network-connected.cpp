class Solution {
public:
    struct DSU{
        vector<int> parent ; 
        vector<int> rank ; 
        public: 
        DSU(int n){
            parent.resize(n,0); 
            rank.resize(n,0) ; 
            for(int i=0;i<n;i++) parent[i] = i ; 
        }

        int find(int node){
            if(parent[node]==node) return node ; 
            return parent[node] = find(parent[node]) ; 
        }

        int unionByRank(int a,int b){
            int root1 = find(a) ; 
            int root2 = find(b) ; 
            if(root1==root2) return false ; 

            if(rank[root1]==rank[root2]){
                rank[root1]++; 
                parent[root2] = root1 ; 
            }else if(rank[root1]>rank[root2]){
                parent[root2] = root1 ;
            }else{
                parent[root1] = root2 ; 
            }
            return true ; 
        }
    }; 

    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU dsu(n) ; 
        int components = n ; 
        int extraEdges = 0 ; 

        for(int i=0;i<connections.size();i++){
            int a = connections[i][0]; 
            int b = connections[i][1] ; 
            if(dsu.unionByRank(a,b)){
                --components ; 
            }else{
                ++extraEdges ; 
            }
        }
        //cout<<components<<" "<<extraEdges<<endl ;
        return components-1<=extraEdges ? components-1 : -1 ; 
    }
};