class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size() ; 
        vector<int> prearr(n+1) ; 

        for(int i=0;i<n;i++){
            int ele = citations[i] ; 
            if(ele>n) prearr[n]++ ; 
            else prearr[ele]++ ; 
        }
        //calculates how many elements in the array are greater than i index 
        for(int i=n-1;i>=0;--i){
            prearr[i] = prearr[i+1] + prearr[i] ;  
        }

        //to find the hindex (max) 
        for(int i=n;i>=0;--i){
            if(i<=prearr[i]) return i ; 
        }

        //doesnot run at all , 
        return 0 ; 
    }
};