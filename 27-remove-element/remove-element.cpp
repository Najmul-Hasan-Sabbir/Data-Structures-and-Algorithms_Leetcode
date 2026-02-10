class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; // The "Writer" pointer
        
        for (int i = 0; i < nums.size(); i++) {
            // If the current element is NOT the one we want to delete
            if (nums[i] != val) {
                // Move it to the front at the writer's position
                nums[k] = nums[i];
                // Move the writer forward
                k++;
            }
        }
        
        
        return k;
    }
};