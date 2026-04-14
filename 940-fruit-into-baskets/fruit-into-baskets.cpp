class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> um;
        int left = 0 ;
        int right = 0 ;
        int maxlen = 0 ;
        while(right<fruits.size()){
            int curele = fruits[right] ;
            if(um.contains(curele)){
                um[curele]++ ;
                right++;
            }
            else if(um.size()<2){
                um[curele] = 1 ;
                right++;
            }else {
                while(1){
                    if(um[fruits[left]]==1){
                        um.erase(fruits[left]) ;
                        left++ ;
                        break ;
                    }else{
                        um[fruits[left]]-- ;
                        left++;
                    }
                }
            }
            int curlen = right - left  ;           
            maxlen = max(maxlen , curlen ) ;
        }
        return maxlen ;
    }
};