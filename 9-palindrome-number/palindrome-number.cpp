class Solution {
public:
    bool isPalindrome(int x) {
        int original = x ;
        long long reverse = 0 ;
        while(x!=0){
            int remainder = x%10 ;
            if(x>0)     reverse = reverse*10 + remainder ;
            else        reverse = reverse*10 - remainder ;

            x = x/10 ;
            cout<<reverse<<" "<<endl ;

        }
        return original == reverse ;
    }
};