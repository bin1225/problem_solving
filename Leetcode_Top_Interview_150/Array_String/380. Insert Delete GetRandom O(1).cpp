#include<bits/stdc++.h>
using namespace std;

class RandomizedSet {
public:
    vector<int> v;
    unordered_map<int,int> hash;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {  
        if(hash.contains(val)) return false;
        hash[val] = v.size();
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(!hash.contains(val)) return false;
        
        int idx = hash[val];
        hash[v.back()] = idx;

        swap(v[idx], v.back());
        
        v.pop_back();
        hash.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */