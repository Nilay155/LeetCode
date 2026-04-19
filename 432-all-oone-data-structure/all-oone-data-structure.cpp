class AllOne {
private:
    unordered_map<string,int> data;
    set<pair<int,string>> countStrings;
public:
    AllOne() {
        countStrings.clear();
        data.clear();
    }
    
    void inc(string key) {
        int c = data[key];
        data[key] += 1;
        countStrings.erase({c,key});
        countStrings.insert({c + 1,key});
    }
    
    void dec(string key) {
        if(data.find(key) == data.end())
            return ;
        
        if(data[key] <= 1) {
            int c = data[key];
            countStrings.erase({c,key});
            data.erase(key);
        }
        else {
            int c = data[key];
            data[key] -= 1;
            countStrings.erase({c,key});
            countStrings.insert({c - 1,key});
        }
    }
    
    string getMaxKey() {
        if(countStrings.empty()) return "";

        auto it = countStrings.rbegin();
        return it -> second;
    }
    
    string getMinKey() {
        if(countStrings.empty()) return "";
        
        auto it = countStrings.begin();
        return it -> second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */