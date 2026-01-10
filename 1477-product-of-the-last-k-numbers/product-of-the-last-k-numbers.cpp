class ProductOfNumbers {
    vector<int> arr;
    int latestZero;
public:
    ProductOfNumbers() {
        latestZero = -1;
    }
    void add(int num) {

        int n = arr.size();
        if(num == 0) {
            latestZero = n;
            arr.push_back(1);
        } else if(arr.empty()){
            arr.push_back(num);
        } else {
            int prod = arr.back() * num;
            arr.push_back(prod);
        }
    }
    
    int getProduct(int k) {
        int n = arr.size();

        if(latestZero != -1 && latestZero >= n-k) return 0;
        else if(n == k) return arr[n-1];
        else return arr[n-1]/arr[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */