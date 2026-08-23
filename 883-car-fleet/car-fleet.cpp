class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        //the idea here is , suppose there is a slower car infront of you , you can never cross it . 
        //but to get the cars in order, you can order them in descing order of their staring position, 
        //after sorting , you just go on cheking in order of staring postion, that , if any car will reach faster than the previous car, if yes you join it with the previous slower car itself , making to a carfleet. this happens till you get a further slower car or which takes more time than the previous slower car. 
        //this basically is a monotonic stack pattern where at last the no of elements in the stacks will represent the total number of car fleets. 

        int size = position.size() ; 
        vector<pair<int,double>> vec(size) ; 
        stack<double> st ; 

        for(int i=0;i<size;++i){
            double timerequired = (target-position[i])/(double)speed[i] ; 
            int pos = position[i] ; 

            vec[i].first = pos ; 
            vec[i].second = timerequired ; 
        }

        //sorting in descending order of their position . 
        sort(vec.begin(),vec.end(),[](const pair<int,double> &a , const pair<int,double> &b){
            return a.first > b.first ; 
        }) ; 

        for(int i=0;i<size;++i){
            double curCarsSpeed = vec[i].second ; 
            //based on position, so the front behind cars can never cross their front ones. 

            if(st.empty() || st.top() < curCarsSpeed){ //only push if behind cars never reach its front car fleet. 
                st.push(curCarsSpeed) ; 
            }
        }

        return st.size() ; 
    }
};