class Solution {
public:
    int strStr(string haystack, string needle) {

        int n = haystack.size();
        int m = needle.size();   


        for (int i = 0; i <= n - m; i++) {

            int j = 0;

            // Compare characters of needle
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }

            // If we matched all characters
            if (j == m) {
                return i;  // return starting index
            }
        }

        // If no match found
        return -1;
    }
};