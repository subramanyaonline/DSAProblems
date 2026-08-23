class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> map = {
            { '{' , '}' }, 
            { '(' , ')' },
            { '[' , ']' }
        }; 

        stack<char> st ; 

        for(char c : s){
            if(map.contains(c)) st.push(c) ; 
            else {
                if(st.empty() || map[st.top()] != c) return false ; 
                st.pop() ; 
            }
        }

        return st.empty() ; 
    }
};