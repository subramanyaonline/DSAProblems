class Solution {
public:
    int gcd(int a, int b) {
        if(a==0) return b ; 
        if(b==0) return a ; 
        return gcd(b,a%b) ; 
    }
    long long gcdSum(vector<int>& nums) {
        int n = nums.size() ; 
        vector<int> prefixgcd(n) ; 
        int maxele = 1 ; 

        for(int i=0;i<n;i++){
            maxele = max(maxele,nums[i]) ; 
            prefixgcd[i] = gcd(nums[i],maxele) ; 
        }

        sort(prefixgcd.begin(),prefixgcd.end()) ; 

        long long totgcd = 0 ; 
        for(int i=0;i<n/2;i++){
            totgcd += gcd(prefixgcd[i],prefixgcd[n-1-i]) ; 
        }

        return totgcd ; 
    }
};