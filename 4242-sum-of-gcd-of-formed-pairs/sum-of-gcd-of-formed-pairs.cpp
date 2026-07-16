class Solution {
public:
    
    long long gcdSum(vector<int>& nums) {
        int n = nums.size() ; 
        vector<int> prefixgcd(n) ; 
        int maxele = 1 ; 

        for(int i=0;i<n;i++){
            maxele = max(maxele,nums[i]) ; 
            //prefixgcd[i] = gcd(nums[i],maxele) ; 
            int a = maxele ;
            int b = nums[i] ; 
            while(true){
                if(a==0){prefixgcd[i] = b ; break ; }
                if(b==0){prefixgcd[i] = a ; break ; }
                int temp = a ; 
                a = b ; 
                b = temp%b ; 
            }
        }


        sort(prefixgcd.begin(),prefixgcd.end()) ; 

        long long totgcd = 0 ; 
        for(int i=0;i<n/2;i++){
            int a = prefixgcd[n-1-i] ;
            int b = prefixgcd[i] ;
            int gcd ;  
            while(true){
                if(a==0){ gcd = b ; break ; }
                if(b==0){ gcd = a ; break ; }
                int temp = a; 
                a = b ; 
                b = temp%b ; 
            }

            totgcd += gcd ; 
        }

        return totgcd ; 
    }
};