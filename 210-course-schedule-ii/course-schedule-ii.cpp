class Solution {
public:
    bool helper(vector<int> &visited, vector<int> &path, vector<vector<int>> &graph, stack<int> &st){
        for(int i=0;i<graph.size();i++){
            if(!dfs(visited,path,graph,st,i)) return false ;
        }
        return true ;
    }

    bool dfs(vector<int> &visited, vector<int> &path, vector<vector<int>> &graph, stack<int> &st,int src){
        if(path[src]==true) return false ;
        if(visited[src]) return true ;

        visited[src] = path[src] = true ;
        for(int i=0;i<graph[src].size();i++){
            if(!dfs(visited,path,graph,st,graph[src][i])) return false  ;
        }

        path[src] = false ;
        st.push(src) ;
        return true ;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses,false) ;
        vector<int> path(numCourses,false) ;//defalut false
        stack<int> st ; 
        vector<int> order ;
        vector<vector<int>> graph(numCourses) ;//default zero 

        for(int i=0;i<prerequisites.size();i++)
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]) ;
        
        if(!helper(visited,path,graph,st)) return {};

        while(!st.empty()){
            order.push_back(st.top()) ;
            st.pop();
        }
        return order ;
    }
};