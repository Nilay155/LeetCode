class MedianFinder {
private:
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
public:
    MedianFinder() {
        maxHeap.push(INT_MIN);
        minHeap.push(INT_MAX);
    }
    // This function should take a number and store it
    void addNum(int num){
        if(maxHeap.size() > minHeap.size()) {
            if(num >= maxHeap.top()) {
                minHeap.push(num);
            } else {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(num);
            }
        } else {
            // maxHeap.size() == minHeap.size()
            if(num >= minHeap.top()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
            } else {
                maxHeap.push(num);
            }
        }
    }
    // This function should return the median of the stored numbers
    double findMedian(){
        int n = maxHeap.size() + minHeap.size();
        if(n == 2) return -1;
        
        if(n & 1) return (double)maxHeap.top();
        else return (double) (maxHeap.top() + minHeap.top()) / 2.00;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */