
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Initialize the Prefix and Suffix arrays
        // We fill them with 1s as the starting multiplier
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);
        vector<int> answer(n);

        // Step 2: Fill the Prefix array (Product of everything to the LEFT)
        // prefix[i] stores the product of all elements from nums[0] to nums[i-1]
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        // Step 3: Fill the Suffix array (Product of everything to the RIGHT)
        // suffix[i] stores the product of all elements from nums[i+1] to nums[n-1]
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        // Step 4: Multiply Prefix and Suffix to get the final answer
        for (int i = 0; i < n; i++) {
            answer[i] = prefix[i] * suffix[i];
        }

        return answer;
    }
};