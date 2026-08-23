class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // the area of the rectangle is restricted by the next and prev smaller elements index. 
        
        int size = heights.size() ; 
        vector<int> leftsmaller(size) ; 
        vector<int> rightsmaller(size) ; 
        stack<int> st ; 

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
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop() ; 
            }
            if(st.empty())  rightsmaller[i] = size ; 
            else rightsmaller[i] = st.top() ; 
            st.push(i) ; 
        }

        int maxarea = 0 ; 
        for(int i=0;i<size;i++){
            int curarea = 
            (rightsmaller[i] - leftsmaller[i] - 1 ) * heights[i] ; 

            maxarea = max(maxarea, curarea) ; 
        }

        return maxarea ; 
    }
};