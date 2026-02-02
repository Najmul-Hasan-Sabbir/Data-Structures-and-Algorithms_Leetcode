class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int max_length = 0;
        int num_of_zeros = 0;

        // j is our scout moving through the whole array
        for (int j = 0,i=0; j < nums.size(); j++) {
            
            // If scout finds a zero, add it to our count
            if (nums[j] == 0) {
                num_of_zeros++;
            }

            // If we have too many zeros, move the anchor 'i'
            // until we kick out a zero from the back
            while (num_of_zeros > k) {
                if (nums[i] == 0) {
                    num_of_zeros--; // We just "un-flipped" this zero
                }
                i++; // Move anchor forward
            }

            // The distance between i and j is our current valid window
            max_length = max(max_length, j - i + 1);
        }

        return max_length;
    }
};