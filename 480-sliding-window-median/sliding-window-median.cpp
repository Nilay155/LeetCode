class Solution {
private:
void f(multiset<int> &first, multiset<int> &second, int num) {

    if(first.size() > second.size()) {

        // move max of first -> second
        if(num < *prev(first.end())) {

            second.insert(*prev(first.end()));
            first.erase(prev(first.end()));
            first.insert(num);

        } else {
            second.insert(num);
        }

    } else { // sizes equal

        // move min of second -> first
        if(num > *second.begin()) {

            first.insert(*second.begin());
            second.erase(second.begin());
            second.insert(num);

        } else {
            first.insert(num);
        }
    }
}
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();
        multiset<int> first,second;
        first.insert(INT_MIN);
        second.insert(INT_MAX);

        for(int i = 0 ; i < k ; i++) {
            f(first,second,nums[i]);
        }

        vector<double> ans;
        
        if(k & 1)
            ans.push_back((double)*first.rbegin());
        else
            ans.push_back(((long long)*first.rbegin() + *second.begin()) / 2.0);

        for(int i = k ; i < n ; i++) {
            
            if(nums[i - k] > *first.rbegin()) { // means second main hain
                auto it = second.find(nums[i - k]);
                second.erase(it);
            } else { // is a part of the first
                auto it = first.find(nums[i - k]);
                first.erase(it);
            }
            f(first,second,nums[i]);

            if(k & 1)
                ans.push_back((double)*first.rbegin());
            else
                ans.push_back(((long long)*first.rbegin() + *second.begin()) / 2.0);
        }
        return ans;
    }
};