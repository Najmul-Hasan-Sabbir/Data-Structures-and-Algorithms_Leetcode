class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        // i = slow pointer
        // It points to the position where the next unique element should be placed
        int i = 0;

        // j = fast pointer
        // It scans the array to find new unique elements
        for (int j = 1; j < nums.size(); j++) {

            // If a new unique element is found
            if (nums[i] != nums[j]) {

                // Move slow pointer forward
                i++;

                // Overwrite the next position with the new unique element
                nums[i] = nums[j];
            }
        }

        // Number of unique elements = i + 1 (because index starts from 0)
        return i + 1;
    }
};
