class Solution {
private:
    vector<int> getLargestNumber(vector<int> &nums,int k) {
        int n = nums.size();
        int drops = n - k;

        stack<int> st;
        for(int i = 0 ; i < n ; i++) {
            while(!st.empty() && st.top() < nums[i] && drops) {
                st.pop();
                drops -= 1;
            }
            st.push(nums[i]);
        }
        while(drops) {
            st.pop();
            drops -= 1;
        }
        
        vector<int> result;
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
    vector<int> mergeNumbers(vector<int> &A,vector<int> &B) {
        int n = A.size(), m = B.size();
        vector<int> largestNumber;
        int i = 0, j = 0;
        // Note : merging two arrays in sorted manner is different than creating the        largest number

        while(i < n && j < m) {

            if(A[i] > B[j]) {
                largestNumber.push_back(A[i]);
                i += 1;
            } else if(B[j] > A[i]) {
                largestNumber.push_back(B[j]);
                j += 1;
            } else {
                // this is where the clash happens
                // A = [1,100], B = [1,20]
                // if I make a move for B then ans = [1B,20B,1A,100A]
                // but if I make a move for A then ans = [1A,100A,1B,20B]
                // moveA > moveB
                // so after the equal signs the element at the largest should be taken

                int u = i + 1, v = j + 1;

                while(u < n && v < m && A[u] == B[v]) {
                    u += 1, v += 1;
                }

                if(v == m) {
                    largestNumber.push_back(A[i]);
                    i += 1;
                } else if(u == n) {
                    largestNumber.push_back(B[j]);
                    j += 1;
                } else {
                    if(A[u] > B[v]) {
                        largestNumber.push_back(A[i]);
                        i += 1;
                    } else {
                        largestNumber.push_back(B[j]);
                        j += 1;
                    }
                }

            }
        }
        while(i < n) {
            largestNumber.push_back(A[i]);
            i += 1;
        }
        while(j < m) {
            largestNumber.push_back(B[j]);
            j += 1;
        }
        return largestNumber;
    }
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        vector<int> ans;
        for(int i = 0 ; i <= k ; i++) {
            int k1 = i, k2 = k - i;
            if(k1 > n || k2 > m) continue;

            // It's possible to make k length number using k1 and k2
            vector<int> A = getLargestNumber(nums1,k1);
            vector<int> B = getLargestNumber(nums2,k2);

            // After getting the two largest numbers we need to merge them the largest possible k-size number

            vector<int> merged = mergeNumbers(A,B);
            if(ans < merged) ans = merged; // this does the lexiographical comparison
        }
        return ans;
    }
};