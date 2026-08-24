class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        //we will caculate the heights at each row using dp 
        //then we are going to apply the monotonic stack 

        int m = matrix.size() ; 
        int n = matrix[0].size() ; 

        vector<vector<int>> heights(m,vector<int>(n,0)) ; 
        int maxarea = 0 ;

        for(int i=0,j=0; j<n ; ++j){
            if(matrix[i][j] == '1'){
                heights[i][j] = 1 ; 
                maxarea = 1 ; 
            }
        }

        for(int i=1;i<m;++i){
            for(int j=0;j<n;++j){
                if(matrix[i][j]=='1'){
                    heights[i][j] = heights[i-1][j] + 1 ;                    
                }
            }
        }
   
        
        for(int i=0;i<m;++i){
            vector<int> pse(n) ;  //previous smaller element 
            stack<int> st ; 

            //pse
            for(int j=0;j<n;++j){
                int curheight = heights[i][j] ; 

                while(!st.empty() && heights[i][st.top()] >= curheight){
                    st.pop() ;  
                }

                if(st.empty()){
                    pse[j] = -1 ; 
                }else{
                    pse[j] = st.top() ; 
                }
                st.push(j) ; 
            }

            while(!st.empty()) st.pop() ; 

            //nse
            for(int j=n-1;j>=0;j--){
                int curheight = heights[i][j] ; 
                int nse ; 

                while(!st.empty() && heights[i][st.top()] >= curheight){
                    st.pop() ;  
                }

                if(st.empty()){
                    nse = n ; 
                }else{
                    nse = st.top() ; 
                }
                st.push(j) ; 

                // now calculating the max area . 
                int height = heights[i][j] ; 
                int width = nse-pse[j]-1 ; 
                int curarea = height*width ; 
                //cout<<curarea<<" " ; 
                maxarea = max(maxarea,curarea) ; 
            }
        }

        return maxarea ; 
    }
};