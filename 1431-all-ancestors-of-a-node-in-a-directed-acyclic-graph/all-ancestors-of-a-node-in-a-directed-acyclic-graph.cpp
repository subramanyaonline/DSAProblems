class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n) ;
        vector<vector<int>> graph(n) ;
        vector<vector<int>> answer(n) ;
        queue<int> q ;

        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]) ;
            indegree[edges[i][1]]++ ;
        }

        for(int i=0;i<n;i++) if(indegree[i]==0) q.push(i) ;

        while(!q.empty()){
            int fromnode = q.front(); 
            for(int i=0;i<graph[fromnode].size();i++){
                // cout<<i<<endl;
                int tonode = graph[fromnode][i] ;
                indegree[tonode]-- ;
                if(indegree[tonode]==0) q.push(tonode) ;
                //adding fromNode to the toNode or i .
                int flag = 0 ; 
                for(int j=0;j<answer[tonode].size();j++){
                    if(answer[tonode][j]<fromnode) continue ;
                    else {
                        answer[tonode].insert(answer[tonode].begin()+j,fromnode) ;              flag = 1 ;
                        break ;
                    }
                }
                // cout<<tonode<<endl ;
                if(!flag) answer[tonode].push_back(fromnode) ;

                //now adding the ancestors of fromnode to the tonode 
                vector<int> temp ;
                int a = 0 , b = 0 , k= 0 ;
                while(a<answer[fromnode].size() && b<answer[tonode].size()){
                    if(answer[fromnode][a]<answer[tonode][b]){
                        temp.push_back( answer[fromnode][a]) ;
                        a++;k++;                       
                    }else if(answer[fromnode][a]>answer[tonode][b]){
                        temp.push_back(answer[tonode][b]) ;
                        b++;k++;
                    }else{
                        temp.push_back(answer[fromnode][a]);
                        a++;b++;k++;
                    }
                }

                while(a<answer[fromnode].size()){
                    temp.push_back(answer[fromnode][a]);
                    a++;k++ ;
                }

                while(b<answer[tonode].size()){
                    temp.push_back(answer[tonode][b]) ;
                    b++;k++;
                }
                answer[tonode] = temp ;
            }
            q.pop() ;
        }
        return answer ;
    }
};