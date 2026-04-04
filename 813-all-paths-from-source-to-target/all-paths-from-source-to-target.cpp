class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans; 
        vector<int> curpath ;

        dfs(graph,0,ans,curpath);
        return ans ;
    }

    void dfs(vector<vector<int>> &graph, int source, vector<vector<int>> &ans, vector<int> &curpath){
        curpath.push_back(source);
        if(source==graph.size()-1){
            ans.push_back(curpath);
        }
        
        for(int neighbour : graph[source]){           
            dfs(graph,neighbour,ans,curpath) ;          
        }

        curpath.pop_back();

    }
};