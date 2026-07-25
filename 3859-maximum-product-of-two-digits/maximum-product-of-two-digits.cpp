class Solution {
public:
    int maxProduct(int n) {
        //METHOD 1 - convert the no to string, then sort. find product of first 2 numbers. 
        //METHOD 2 - find first max and second max in the string . 

        string str = to_string(n) ; 
        int firstmax = 0;
        int secondmax = 0; 
        for(int i=0;i<str.size();i++){
            if(str[i]>=firstmax){
                secondmax = firstmax ; 
                firstmax = str[i] ; 
            }else if(str[i]>=secondmax){
                secondmax = str[i] ; 
            }
        }
        firstmax = firstmax - '0'; 
        secondmax = secondmax - '0' ; 
        return firstmax*secondmax ; 
        
    }
};