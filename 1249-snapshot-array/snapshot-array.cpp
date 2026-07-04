class SnapshotArray {
private:
    unordered_map<int,unordered_map<int,int>> snapShots;
    unordered_map<int,int> snapReferenceNumber;
    int snapNumber = 0;
    int size = 0;
    int flag = 0;
public:
    SnapshotArray(int length) {
        this -> size = length;
        this -> snapShots.clear();
        this -> snapReferenceNumber.clear();
        this -> snapNumber = 0;
        this -> flag = 0;
    }
    
    void set(int index, int val) {
        int refNumber = snapReferenceNumber[snapNumber];
        if(snapShots.find(refNumber) != snapShots.end()
        && snapShots[refNumber].find(index) != snapShots[refNumber].end() 
        && snapShots[refNumber][index] == val)
            return ;
        
        
        if(refNumber != snapNumber && (snapShots.empty() || snapShots[snapNumber].empty()) ) {
            snapShots[snapNumber] = snapShots[refNumber];
        } 
        flag = 1;
        snapShots[snapNumber][index] = val;
        snapReferenceNumber[snapNumber] = snapNumber;
    }
    
    int snap() {
        snapNumber += 1;
        if(flag == 1) {
            snapShots[snapNumber] = snapShots[snapNumber - 1]; // state carry
            snapReferenceNumber[snapNumber] = snapNumber;
        } else {
            snapReferenceNumber[snapNumber]=snapReferenceNumber[snapNumber - 1];
        }
        flag = 0;
        return snapNumber - 1;
    }
    
    int get(int index, int snap_id) {
        snap_id = snapReferenceNumber[snap_id];
        if(snapShots.find(snap_id) == snapShots.end())
            return 0;
        
        if(snapShots[snap_id].find(index) == snapShots[snap_id].end())
            return 0;
        
        return snapShots[snap_id][index];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */