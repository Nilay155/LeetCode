class Node {
public:
    int key, val;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        val = v;
        prev = next = nullptr;
    }
};

class LRUCache {
public:
    unordered_map<int, Node*> keyNode;
    Node* head;
    Node* tail;

    LRUCache() {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void remove(int key) {
        Node* curr = keyNode[key];
        keyNode.erase(curr->key);

        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
    }

    void add(int key, int value) {
        Node* curr = new Node(key, value);
        keyNode[key] = curr;

        Node* node = tail->prev;
        node->next = curr;
        curr->prev = node;
        curr->next = tail;
        tail->prev = curr;
    }

    int removeHead() {
        Node* node = head->next;
        if (node == tail) return -1; // empty

        keyNode.erase(node->key);

        head->next = node->next;
        node->next->prev = head;

        int k = node->key;
        delete node;
        return k;
    }

    bool empty() {
        return head->next == tail;
    }
};

class LFUCache {
private:
    unordered_map<int, int> keyLevel;       // key -> freq
    unordered_map<int, LRUCache*> lvlCache; // freq -> LRUCache
    unordered_map<int, int> keyValue;       // key -> value
    int capacity;
    int lfu;

public:
    LFUCache(int cap) {
        capacity = cap;
        lfu = 0;
    }

    int get(int key) {
        if (keyValue.find(key) == keyValue.end()) return -1;

        int val = keyValue[key];
        int currLvl = keyLevel[key];
        int newLvl = currLvl + 1;

        lvlCache[currLvl]->remove(key);
        if (lvlCache[currLvl]->empty() && lfu == currLvl)
            lfu++;

        if (lvlCache.find(newLvl) == lvlCache.end())
            lvlCache[newLvl] = new LRUCache();

        lvlCache[newLvl]->add(key, val);
        keyLevel[key] = newLvl;

        return val;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        // key already exists
        if (keyValue.find(key) != keyValue.end()) {
            keyValue[key] = value;
            get(key); // bump frequency
            return;
        }

        // need to evict
        if (keyValue.size() >= capacity) {
            int deletedKey = lvlCache[lfu]->removeHead();
            keyValue.erase(deletedKey);
            keyLevel.erase(deletedKey);
        }

        // new key always goes to freq=1
        keyValue[key] = value;
        keyLevel[key] = 1;
        lfu = 1;

        if (lvlCache.find(1) == lvlCache.end())
            lvlCache[1] = new LRUCache();

        lvlCache[1]->add(key, value);
    }
};
