class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,int> open = {{'(',1},{'[',2},{'{',3}} ; 
        unordered_map<char,int> close = {{')',1},{']',2},{'}',3}} ; 
        stack<char> st ; 

        int size = s.size() ; 
        
        for(int i=0;i<size;++i){

            char curchar = s[i] ; 

            if(open.contains(curchar)) st.push(curchar) ; 
            
            else{
                //curchar is closing 
               if(st.empty()) return false ; 
                if(close.contains(st.top())) return false ; 

               int curBracketNo = close[curchar] ; //barcket number 
               int topBracketNo = open[st.top()] ; 

               if( curBracketNo != topBracketNo ) return false ;
               else st.pop() ; 
            }
        }
        if(st.empty()) return true ; 
        return false ; 
    }
};