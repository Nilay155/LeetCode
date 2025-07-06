class LRUCache {
private:
    unordered_map<int,int> keyValue;
    unordered_map<int,int> latest;
    queue<pair<int,int>> q;
    int counter = 0;
    int size = 0;
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(keyValue.find(key) != keyValue.end()) {

            if(latest[key] >= q.front().second) {
                q.push({key,++counter});
                latest[key] = counter;
                return keyValue[key];
            }
            else {
                return -1;
            }

        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(keyValue.find(key) != keyValue.end() && latest[key] >= q.front().second) {
            // updation operation
            q.push({key,++counter});
            keyValue[key] = value;
            latest[key] = counter;
            return;
        }
        q.push({key,++counter});
        keyValue[key] = value;
        latest[key] = counter;
        while(!q.empty() && latest[q.front().first] != q.front().second) {
            q.pop();
        }
        if(keyValue.size() > size) {
            // Remove LRU
            if(!q.empty()) {
                int evictKey = q.front().first;
                q.pop();
                keyValue.erase(evictKey);
                latest.erase(evictKey);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */