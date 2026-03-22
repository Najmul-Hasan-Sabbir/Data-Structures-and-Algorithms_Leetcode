class Solution {
public:

    // helper function : counts 1s in binary of a number
    int countOnes(int num) {
        int count = 0;

        while (num > 0) {
            count += num % 2;  // if last digit is 1 , add it
            num = num / 2;     // remove last digit , move to next
        }

        return count;
    }

    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);

        // for each number , call countOnes and store result
        for (int i = 1; i <= n; i++) {
            ans[i] = countOnes(i);
        }

        return ans;
    }
};