/*
    time: 30min 
    success: false
    note: queue활용해보려다가 실패. 실제 LRU처럼 구성하려면 list를 활용하는 게 맞다. 
    idea는 splice함수의 활용, map에 list의 iterator type을 value로 설정하는 것.
    list<pair<int,int>>* 와 list<pari<int,int>>::iterater의 차이는 실제 리스트 자체의 포인터를 가리키냐 vs 리스트 내부 노드를 가리키냐.
*/
#include<bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    list<pair<int,int>> l;
    unordered_map<int, list<pair<int,int>>::iterator> m;
    int size;
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(m.contains(key)) {
            l.splice(l.begin(), l, m[key]); //l에서 m[key]위치 노드를 l.begin()앞에 붙인다.
            return m[key]->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.contains(key)) {
            l.splice(l.begin(), l, m[key]); 
            m[key]->second = value;
            return;
        }

        if(size == l.size()) {
            auto delete_key = l.back().first;
            l.pop_back();
            m.erase(delete_key);
        }
        l.push_front({key,value});
        m[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */