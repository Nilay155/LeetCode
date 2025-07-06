struct Cache {
    unordered_set<int> s;
    queue<int> q;
};
class LFUCache {
private:
    unordered_map<int,int> keyValue;
    unordered_map<int,Cache> freq;
    unordered_map<int,int> keyFreq;
    int size;
    int minFreq;
public:
    LFUCache(int capacity) {
        size = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if(keyValue.find(key) != keyValue.end()) {
            int currFreq = keyFreq[key];

            freq[currFreq].s.erase(key);
            if(freq[currFreq].s.size() == 0 && currFreq == minFreq) minFreq = currFreq + 1;
            freq[currFreq+1].s.insert(key);
            freq[currFreq+1].q.push(key);

            keyFreq[key] = currFreq+1;

            return keyValue[key];
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        // Deletion
        if(keyValue.size() >= size && keyValue.find(key) == keyValue.end()) {
            // new-insertion

            while(!freq[minFreq].q.empty() && 
            !freq[minFreq].s.count(freq[minFreq].q.front())) {
                freq[minFreq].q.pop();
            }
            int element = freq[minFreq].q.front();
            freq[minFreq].q.pop();
            freq[minFreq].s.erase(element);
            keyValue.erase(element);
            keyFreq.erase(element);

            keyValue.insert({key,value});
            keyFreq.insert({key,1});
            freq[keyFreq[key]].s.insert(key);
            freq[keyFreq[key]].q.push(key);
            
            minFreq = 1;
            return;
        }
        // insertion
        if(keyValue.find(key) == keyValue.end()) {
            keyValue.insert({key,value});
            keyFreq.insert({key,1});
            freq[keyFreq[key]].s.insert(key);
            freq[keyFreq[key]].q.push(key);

            minFreq = 1;
        } 
        // updation
        else {
            keyValue[key] = value;
            int currFreq = keyFreq[key];

            freq[currFreq].s.erase(key);
            if(freq[currFreq].s.size() == 0 && currFreq == minFreq) minFreq = currFreq + 1;
            freq[currFreq+1].s.insert(key);
            freq[currFreq+1].q.push(key);
            keyFreq[key] = currFreq+1;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */