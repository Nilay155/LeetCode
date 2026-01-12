class NumberContainers {
private:
    unordered_map<int,int> indexValue;
    unordered_map<int,set<int>> smallestIndex;
public:
    NumberContainers() {
        indexValue.clear();
        smallestIndex.clear();
    }
    
    void change(int index, int number) {
        if(indexValue.find(index) != indexValue.end()) {
            int k = indexValue[index];
            smallestIndex[k].erase(index);
        }
        indexValue[index] = number;
        smallestIndex[number].insert(index);
    }
    
    int find(int number) {
        if(smallestIndex[number].empty()) return -1;
        else return *smallestIndex[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */