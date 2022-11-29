class RandomizedSet {
public:
    unordered_map<int, int> mapping;
    vector<int> num;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(mapping[val]>0)
            return false;
        num.push_back(val);
        mapping[val] = num.size();
        return true;
    }
    
    bool remove(int val) {
        if(mapping[val]>0){
            if(mapping[val]==num.size()){
                mapping[val] = 0;
                num.pop_back();
            }
            else{
                mapping[num[num.size()-1]] = mapping[val];
                int i = mapping[val]-1;
                mapping[val] = 0;
                swap(num[i], num[num.size()-1]);
                num.pop_back();
            }
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return num[rand() % num.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */