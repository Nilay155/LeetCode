class MapSum {
public:
    unordered_map<string,int> prefixMap;
    unordered_map<string,int> currValue;
    MapSum() {
        prefixMap.clear();
        currValue.clear();
    }
    
    void insert(string key, int val) {
        int n = key.length();
        if(currValue.find(key) != currValue.end()) {
            int prevValue = currValue[key];
            string str;
            for(int i = 0 ; i < n ; i++) {
                str += key[i];
                prefixMap[str] -= prevValue;
            }
        }
        currValue[key] = val; 
        string str;
        for(int i = 0 ; i < n ; i++) {
            str += key[i];
            prefixMap[str] += val;
        }
    }
    
    int sum(string prefix) {
        return prefixMap[prefix];
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */