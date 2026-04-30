class Solution {
public:

    bool helper(vector<vector<int>> &adjlist, vector<bool> &visited){
        unordered_set<int> path ; 
        for(int i=0;i<adjlist.size();i++){
            if(!dfs(adjlist,visited,i,path)) return false;
        }
        return true ;
    } ;

    bool dfs(vector<vector<int>> &adjlist, vector<bool> &visited, int src, unordered_set<int> &path){
        if(path.contains(src)) return false ;
        if(visited[src]) return true ;
        visited[src] = true ;
        path.insert(src) ;
        for(int i=0;i<adjlist[src].size();i++){
            if(!dfs(adjlist,visited,adjlist[src][i],path)) return false ;
        }
        path.erase(src) ;
        return true ;
    } ;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlist(numCourses) ;

        for(int i=0;i<prerequisites.size();i++){
            adjlist[prerequisites[i][1]].push_back(prerequisites[i][0]) ;
        }

        vector<bool> visited(numCourses) ;

        return helper(adjlist,visited) ;
    }
};