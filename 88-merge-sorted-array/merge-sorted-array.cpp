class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Step 1: Create the extra vector to hold the result
        vector<int> result(m + n);

        int i = 0;      // Pointer for nums1 (starts at the beginning)
        int j = 0;      // Pointer for nums2 (starts at the beginning)
        int k = 0;      // Pointer for our new result vector

        // Step 2: While there are elements in both arrays, pick the smaller one
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                result[k] = nums1[i];
                i++;
            } else {
                result[k] = nums2[j];
                j++;
            }
            k++;
        }

        // Step 3: If nums1 still has elements left, copy them
        while (i < m) {
            result[k] = nums1[i];
            i++;
            k++;
        }

        // Step 4: If nums2 still has elements left, copy them
        while (j < n) {
            result[k] = nums2[j];
            j++;
            k++;
        }

        // Step 5: Overwrite the original nums1 with our result
        // This is necessary because the return type is void
        nums1 = result;
    }
};