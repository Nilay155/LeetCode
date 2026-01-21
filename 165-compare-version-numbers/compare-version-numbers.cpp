class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.length(), m = version2.length();

        int i = 0, j = 0;

        while(i < n || j < m) {
            long long revision1 = 0, revision2 = 0;
            while(i < n && version1[i] != '.') {
                revision1 = revision1 * 10 + version1[i] - '0';
                i++;
            }
            while(j < m && version2[j] != '.') {
                revision2 = revision2 * 10 + version2[j] - '0';
                j++;
            }

            if(revision1 > revision2) return 1;
            if(revision2 > revision1) return -1;
            i += 1;
            j += 1;
        }
        return 0;
    }
};