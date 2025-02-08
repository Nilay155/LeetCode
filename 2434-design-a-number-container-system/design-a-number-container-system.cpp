class NumberContainers {
private:
    unordered_map<int,int> indexMap;
    unordered_map<int,set<int>> numberMap;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(indexMap.find(index) != indexMap.end()) {
            numberMap[indexMap[index]].erase(index);
        }
        indexMap[index] = number;
        numberMap[number].insert(index);
    }
    
    int find(int number) {
        if(numberMap.find(number) != numberMap.end()) {
            // set<int> st = numberMap[number];
            if(numberMap[number].size() < 1) return -1;
            int ele = *numberMap[number].begin();
            return ele;
        } else {
            return -1;
        }
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */