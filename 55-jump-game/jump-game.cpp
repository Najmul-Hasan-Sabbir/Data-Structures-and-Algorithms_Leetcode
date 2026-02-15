class Solution {
public:
    bool canJump(vector<int>& nums) {

        /*
        Intuition:

        1. The problem only cares if I can reach the LAST index,
           not about the actual path.

        2. So I will track only one thing:
           the farthest index I can reach so far (max_reach).

        3. While traversing:
           - If at any point my current index i is greater than max_reach,
             it means I cannot even stand on this index.
             So the answer is false.

        4. Otherwise:
           - From this index, I update how far I can go:
             max_reach = max(max_reach, i + nums[i])

        5. If I finish the loop without getting stuck,
           it means the last index is reachable.
        */

        int n = nums.size();
        int max_reach = 0; // farthest index reachable so far

        for(int i = 0; i < n; i++) {

            // If I can't even reach this index, I'm stuck
            if(i > max_reach) 
                return false;

            // Update the farthest position I can reach
            max_reach = max(max_reach, i + nums[i]);
        }

        // If we never got stuck, we can reach the end
        return true;
    }
};
