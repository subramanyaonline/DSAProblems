class Solution {
public:
    int getLength(vector<int>& nums) {
        
        //max freq should be twice as other frequencies, noless, no more. 
        //sliding window. rightfreq. when window gets unworthy, you have two choices either to expand from right till it gets worty or shrink from left till it becomes worthy. 
        //before expanding from right we have to check if it ever gets worthy, that is
        //got few hints, and im saying this is not a sliding window problem as shrinking is not possible as this question is not monotonic, very big hint actually, a window can become valid from invalid . 

        //so from every point i will be the starting , we just have to calculate the ending point . 
        //very good question and improves your thinking capability and use constraints carefully . len is less than 1000.
        
        int maxlen = 1 ; 
    
        for(int i=0;i<nums.size();i++){//considering i as starting point .
            unordered_map<int,int> freq;
            freq[nums[i]] = 1 ;
            int maxfreq = 1 ;
            
            unordered_map<int,int> countele ;
            countele[1] = 1 ;
            
            for(int j=i+1;j<nums.size();j++){
                if(freq.count(nums[j])) countele[freq[nums[j]]]--;
                freq[nums[j]]++; 
                countele[freq[nums[j]]]++; 

                int distinctele = freq.size() ; 
                maxfreq = max(maxfreq,freq[nums[j]]) ;if(distinctele==1){
                     maxlen = max(maxlen,j-i+1) ; 
                     continue ; 
                }
                if(countele[maxfreq]+countele[maxfreq/2]==distinctele && maxfreq%2==0 && countele.count(maxfreq/2) && countele[maxfreq/2]>0){
                    maxlen = max(maxlen, j-i+1) ; 
                }
            }           
        }
        return maxlen ;
    }
};