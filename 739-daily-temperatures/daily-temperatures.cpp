class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //we have to keep a monotonically decresing stack from teh right side
        stack<int> st ; //stack of indices ; 
        int size = temperatures.size() ; 
        vector<int> ans(size) ; 

        for(int i=size-1 ; i>= 0 ; --i){
            int curtemp = temperatures[i] ; 

            while(!st.empty() && temperatures[st.top()] <= curtemp){
                st.pop() ; 
            }
            if(st.empty()) ans[i] = 0 ; 
            else ans[i] = st.top()-i ; 
            st.push(i) ; 
        }

        return ans ; 
    }
};