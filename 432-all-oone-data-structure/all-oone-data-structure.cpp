class FreqNode {
public:
    unordered_set<string> keys;
    FreqNode* prev;
    FreqNode* next;

    FreqNode(string key) {
        prev = next = nullptr;
        if (key != "") keys.insert(key);
    }
};

class AllOne {
private:
    unordered_map<string, int> data;
    unordered_map<int, FreqNode*> freqNodes;

    FreqNode* head;
    FreqNode* tail;

    void handleDelete(FreqNode* node) {
        FreqNode* p = node->prev;
        FreqNode* n = node->next;

        p->next = n;
        n->prev = p;
        delete node;
    }

    void increment(string key, int c, int nc) {
        FreqNode* prevNode = freqNodes[c];
        if(!prevNode -> keys.empty())
            prevNode->keys.erase(key);

        FreqNode* curr;

        if (freqNodes.find(nc) == freqNodes.end()) {
            curr = new FreqNode(key);

            FreqNode* nxt = prevNode->next;
            prevNode->next = curr;
            curr->prev = prevNode;
            curr->next = nxt;
            nxt->prev = curr;

            freqNodes[nc] = curr;
        } else {
            curr = freqNodes[nc];
            curr->keys.insert(key);
        }

        if (prevNode != head && prevNode->keys.empty()) {
            freqNodes.erase(c);
            handleDelete(prevNode);
        }
    }

    void decrement(string key, int c, int nc) {
        FreqNode* currNode = freqNodes[c];
        if(!currNode -> keys.empty())
            currNode->keys.erase(key);

        FreqNode* prevNode;

        if (freqNodes.find(nc) == freqNodes.end()) {
            prevNode = new FreqNode(key);

            FreqNode* before = currNode->prev;
            before->next = prevNode;
            prevNode->prev = before;
            prevNode->next = currNode;
            currNode->prev = prevNode;

            freqNodes[nc] = prevNode;
        } else {
            prevNode = freqNodes[nc];
            prevNode->keys.insert(key);
        }

        if (currNode->keys.empty()) {
            freqNodes.erase(c);
            handleDelete(currNode);
        }
    }

    void eraseKey(string key, int c) {
        FreqNode* node = freqNodes[c];
        node->keys.erase(key);

        if (node->keys.empty()) {
            freqNodes.erase(c);
            handleDelete(node);
        }
    }

public:
    AllOne() {
        head = new FreqNode("");
        tail = new FreqNode("");

        head->next = tail;
        tail->prev = head;

        freqNodes[0] = head;
    }

    void inc(string key) {
        int c = data[key];
        data[key]++;

        increment(key, c, c + 1);
    }

    void dec(string key) {
        if (data.find(key) == data.end()) return;

        int c = data[key];

        if (c == 1) {
            data.erase(key);
            eraseKey(key, c);
        } else {
            data[key]--;
            decrement(key, c, c - 1);
        }
    }

    string getMaxKey() {
        if (tail->prev == head) return "";
        return *(tail->prev->keys.begin());
    }

    string getMinKey() {
        if (head->next == tail) return "";
        return *(head->next->keys.begin());
    }
};