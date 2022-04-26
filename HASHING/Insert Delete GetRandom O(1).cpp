class RandomizedSet {
public:
    unordered_map<int,int>mp;
    vector<int>v;
    RandomizedSet() {
     
    }

    bool insert(int val) {
        if(mp.find(val)!=mp.end()) //value present 
            return false;
        v.push_back(val);
        mp[val]=v.size()-1;
            return true;
    }
    
    bool remove(int val) {
        //if val  not prsent 
        if(mp.find(val)==mp.end()) 
            return false;
        int i=mp[val];
        int n=v.size()-1;
        mp[v[n]]=i;
        swap(v[n],v[i]);
        v.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int n=v.size();
        int idx=rand()%n;
        return v[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
