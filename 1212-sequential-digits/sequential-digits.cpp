class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string str = "123456789" ; 
        string start = to_string(low) ; 
        int startsize = start.size(); 
        string end = to_string(high) ; 
        int endsize = end.size() ; 
        vector<int> ans ; 


        for(int i=startsize; i<=endsize;i++){
            string s ; 
            for(int j=0;j<i;j++){
                s.push_back(str[j]); 
            }

            for(int j=i ; j<9;j++){
                if(s.size()>startsize && s.size()<endsize){
                    ans.push_back(stoi(s)) ;
                } 
                else if(startsize==endsize){
                    if(s<=end && s>=start) ans.push_back(stoi(s)); 
                }
                else if(s.size()==startsize && s>=start){
                    ans.push_back(stoi(s)); 
                }else if(s.size()==endsize && s<=end){
                    ans.push_back(stoi(s)); 
                }
                s.erase(0,1) ;  
                s.push_back(str[j]); 
            }
            if(s.size()>startsize && s.size()<endsize){
                ans.push_back(stoi(s)) ; 
            }
            else if(startsize==endsize){
                if(s<=end && s>=start) ans.push_back(stoi(s));  
            }else if(s.size()==startsize && s>=start){
                ans.push_back(stoi(s)); 
            }else if(s.size()==endsize && s<=end){
                ans.push_back(stoi(s)); 
            }
        }
        
        return ans ; 
    }
};