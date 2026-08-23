class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // the area of the rectangle is restricted by the next and prev smaller elements index. 
        
        int size = heights.size() ; 
        vector<int> leftsmaller(size) ; 
        stack<int> st ; 
        int maxarea = 0 ; 

        for(int i=0;i<heights.size();++i){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop() ; 
            }
            if(st.empty())  leftsmaller[i] = -1 ;
            else leftsmaller[i] = st.top() ; 
            st.push(i) ; 
        }

        while(!st.empty()) st.pop(); 

        for(int i=size-1;i>=0;--i){
            int rightsmaller ; 
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop() ; 
            }
            if(st.empty())  rightsmaller = size ; 
            else rightsmaller = st.top() ; 
            st.push(i) ; 

            int curarea = (rightsmaller-leftsmaller[i]-1)*heights[i] ;
            maxarea = max(maxarea,curarea) ;  
        }

        return maxarea ; 
    }
};