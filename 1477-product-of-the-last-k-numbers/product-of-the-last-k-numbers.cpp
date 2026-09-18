class ProductOfNumbers {
private:
    vector<int> prefixProducts;
    int lastZero;
public:
    ProductOfNumbers() {
        prefixProducts.clear();
        lastZero = -1;
    }
    
    void add(int num) {
        
        if(prefixProducts.empty()) {

            if(num == 0)
                prefixProducts.push_back(1), lastZero = prefixProducts.size();
            else
                prefixProducts.push_back(num);

        } else {

            if(num == 0)
                prefixProducts.push_back(1), lastZero = prefixProducts.size();
            else {
                int back = prefixProducts.back();
                int product = num * back;
                prefixProducts.push_back(product);
            }
        }
        return ;
    }
    
    int getProduct(int k) {
        int sz = prefixProducts.size();
        if(sz < k)
            return 0;
        if(lastZero > sz - k) 
            return 0;
        
        int k1 = prefixProducts[sz - 1];
        int k2 = (sz - k - 1 >= 0) ? prefixProducts[sz - k - 1] : 1;

        return k1 / k2;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */