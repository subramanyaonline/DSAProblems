class RandomizedSet {
    unordered_set<int> set ; 
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(set.contains(val)) return false; 
        set.insert(val) ; 
        return true ; 
    }
    
    bool remove(int val) {
        if(set.contains(val)){
            set.erase(val) ; 
            return true ;
        }
        return false ;
    }
    
    int getRandom() {
        int size = set.size() ; 
        int random = rand() % size ; 

        auto it = next(set.begin(),random) ; 
        return *it ; 
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */