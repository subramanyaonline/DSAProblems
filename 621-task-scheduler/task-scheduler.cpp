class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // i think i have to remove n elements with max freq from heap . 
        // we can reduce the freq of all items by one ,and add again to heap 
        // a short would be to reduce the freq by min(all removed items).
        // if your dont get to remove n items,(only x gets removed) then n*min(removed)
        //push again all elements after reducing them min(removed) times. then repeat same process again  

         
        if(n==0) return tasks.size(); //no gap required 

        vector<int> freq(26) ; 
        for(int i=0;i<tasks.size();++i){
            freq[tasks[i]-'A']++ ; 
        }

        priority_queue<int> pq ; 
        for(int i=0;i<26;i++){
            if(freq[i]) pq.push(freq[i]) ; //only push if freq is > zero 
        }

        vector<int> removed(n+1) ;

        int totaltime = 0 ; 
        int x = 0 ; //to mark the last iteration , we have to remove (n+1-i), cause the last process ends , no need to add theextra inbetweeen time . 

        while(!pq.empty()){
            x = 0 ; 
            for(int i=0;i<n+1;i++){
                if(pq.empty()){ 
                    removed[i] = -1 ; 
                    totaltime += n+1-i ; 
                    x = i ; 
                    break ; 
                }
                removed[i] = pq.top()-1 ; pq.pop() ;  
                totaltime++ ; 
            }

            for(int i=0;i<n+1;i++){
            
                if(removed[i]==-1) {  //the end of removed list 
                    break ;
                }  
                else {
                    if(removed[i]) pq.push(removed[i]) ; //if freq is > 0 
                }
            }
        }

        if(x>0)return totaltime - (n+1-x); // in the last iteration, once the last element gets removed, you dont need tiem to reach till n timeslot ,
        return totaltime ;  
    }
};