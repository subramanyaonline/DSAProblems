class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses) ;
        vector<vector<int>> adjlist(numCourses) ;
        queue<int> q ; 
        vector<bool> visited(numCourses) ; 

        for(int i=0;i<prerequisites.size();i++){
            indegree[prerequisites[i][1]]++; 
            adjlist[prerequisites[i][0]].push_back(prerequisites[i][1]); 
        }

        for(int i=0;i<indegree.size();i++){
            if(!indegree[i]){
                q.push(i) ;
                visited[i] = true ; 
            }  
        }

        while(!q.empty()){
            int src = q.front(); 
            q.pop() ; 
            for(int dest : adjlist[src]){
                if(!--indegree[dest]){
                    q.push(dest) ; //if 0 then push 
                    visited[dest] = true ;
                }
            }
        }

        for(int i=0;i<numCourses;i++){
            if(indegree[i]) return false ;
        }
        return true ;
    }
};