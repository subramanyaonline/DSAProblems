class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int size = tokens.size() ; 
        stack<int> st ; 

        for(int i=0;i<size;++i){
            string str = tokens[i] ; 

            if(str=="*"){
                int b = st.top(); 
                st.pop(); 
                int a = st.top(); 
                st.pop() ; 
                st.push(a*b) ; 
            }else if(str=="+"){
                int b = st.top(); 
                st.pop(); 
                int a = st.top(); 
                st.pop() ; 
                st.push(a+b) ;
            }else if(str=="/"){
                int b = st.top(); 
                st.pop(); 
                int a = st.top(); 
                st.pop() ; 
                st.push(a/b) ;
            }else if(str=="-"){
                int b = st.top(); 
                st.pop(); 
                int a = st.top(); 
                st.pop() ; 
                st.push(a-b) ;
            }else{
                st.push(stoi(str)); 
            }
        }
        return st.top() ; 
    }
};