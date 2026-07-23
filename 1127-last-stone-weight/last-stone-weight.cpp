class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>> pq(stones.begin(),stones.end()) ; 

        while(pq.size()>1){
            int first = pq.top() ; pq.pop(); 
            int second = pq.top() ; pq.pop() ; 
            if(first == second) continue ; 
            pq.push(first-second) ; 
        }
        return pq.size()==0 ? 0 : pq.top() ; 
    }
};