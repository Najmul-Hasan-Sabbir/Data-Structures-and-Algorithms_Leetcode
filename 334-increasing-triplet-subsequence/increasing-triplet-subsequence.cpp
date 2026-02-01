class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        int smallest=INT_MAX;
        int sec_smallest=INT_MAX;
        int last_val=INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            // Case 1: Current is the smallest seen so far
            if (nums[i] <= smallest) {
                smallest = nums[i];
            }
            // Case 2: Current is bigger than smallest, but smaller than sec_smallest
            else if (nums[i] <= sec_smallest) {
                sec_smallest = nums[i];
            }
            // Case 3: Current is bigger than both! Triplet found.
            else {
                return true;
            }
        }



return false;
    }
};