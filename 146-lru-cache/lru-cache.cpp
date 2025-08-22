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
private:
    unordered_map<int, Node*> keyNode;
    Node* head;
    Node* tail;
    int capacity;

    void addNode(Node* node) {
        Node* prev = tail->prev;
        prev->next = node;
        node->prev = prev;
        node->next = tail;
        tail->prev = node;
    }

    void removeNode(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

public:
    LRUCache(int cap) {
        capacity = cap;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (keyNode.find(key) == keyNode.end())
            return -1;
        Node* node = keyNode[key];
        removeNode(node);
        addNode(node);
        return node->val;
    }

    void put(int key, int value) {
        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            node->val = value;
            removeNode(node);
            addNode(node);
        } else {
            if (keyNode.size() == capacity) {
                Node* lru = head->next;
                removeNode(lru);
                keyNode.erase(lru->key);
                delete lru;
            }
            Node* node = new Node(key, value);
            addNode(node);
            keyNode[key] = node;
        }
    }
};
