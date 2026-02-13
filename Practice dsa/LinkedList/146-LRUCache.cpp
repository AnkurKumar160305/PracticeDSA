class LRUCache {
    vector<pair<int,int> v;
    int size;
public:
    LRUCache(int capacity) {
        this->size=capacity;
    }
    
    int get(int key) {
        int val=-1;
        for(int i=0;i<v.size();i++){
            if(v[i]==key){
                val=v[i].second;
                v.erase(v.begin()+i);
                v.push_back({key,val});
            }
        }
        return val;
    }
    
    void put(int key, int value) {
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */