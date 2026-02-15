class Solution {
public:
    int jump(vector<int>& nums) {

        /*
        My  Intuition:

        1. The problem asks for minimum number of steps,
           so greedy is a natural choice.

        2. Instead of trying all paths, I track ranges:
           - curr_end: how far I can go with current jump
           - farthest: best possible reach for next jump

        3. I scan all positions in current range.
           While scanning, I keep updating farthest.

        4. When I reach curr_end,
           it means current jump is exhausted.
           So I must take a new jump and update the range.

        5. I only iterate till n-1 because
           once I reach the last index, no more jumps are needed.
        */

        int n = nums.size();
        int curr_end = 0;   // end of current jump range
        int farthest = 0;   // farthest index for next jump
        int jump = 0;       // total jumps

        for(int i = 0; i < n-1; i++) {

            // update the best possible future reach
            farthest = max(farthest, i + nums[i]);

            // if we reached the end of current range
            if(i == curr_end) {
                jump++;              // we must take a jump
                curr_end = farthest; // update new range
            }
        }

        return jump;
    }
};
