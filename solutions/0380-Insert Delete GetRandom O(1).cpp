class RandomizedSet {
public:
    vector<int> v;
    unordered_map<int, int> valtoIndex;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(valtoIndex.find(val) != valtoIndex.end())
        {
            return false;
        }

        valtoIndex[val] = v.size();

        v.push_back(val);

        return true;
    }
    
    bool remove(int val) {
        if(valtoIndex.find(val) == valtoIndex.end())
        {
            return false;
        }

        int lastVal = v.back();

        int idx = valtoIndex[val];

        v[idx] = lastVal;

        valtoIndex[lastVal] = idx;

        v.pop_back();
        valtoIndex.erase(val);

        return true;
    }
    
    int getRandom() {
        int randIdx = rand() % v.size();

        return v[randIdx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
