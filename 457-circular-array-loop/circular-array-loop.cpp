class Solution {
private:
    int nextPosition(int p,int k,int n) {
        return (((p + k) % n) + n) % n;
    }
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();    
        for(int i = 0 ; i < n ; i++) {
            if(i == nextPosition(i,nums[i],n)) nums[i] = 1111; // self-loop
        }
        for(int i = 0 ; i < n ; i++) {
            if(nums[i] == 1111) continue; // dead - end to a SLL not a CLL  

            bool flag = (nums[i] > 0);
            int slow = i, fast = i;

            while(true) {
                // fast-pointer
                if(nums[fast] != 1111 && (nums[fast] > 0) == flag) { // pos-neg sequence check
                    int nx = nextPosition(fast,nums[fast],n);
                    fast = nx;
                    if(nums[fast] != 1111 && ((nums[fast] > 0) == flag)) {
                        int nx = nextPosition(fast,nums[fast],n);
                        fast = nx;
                    } else {
                        break;
                    }
                } else {
                    break;
                }
                // slow pointer
                int nx = nextPosition(slow,nums[slow],n);
                slow = nx;
                // cycle check
                if(slow == fast) {
                    // cout << slow << "   " << fast << "   " << i ;
                    return true;
                }
            }

        }
        return false;
    }
};