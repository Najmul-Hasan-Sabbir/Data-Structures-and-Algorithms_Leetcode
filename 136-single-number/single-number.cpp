/* My intuition:
1. If I XOR a number with itself, it disappears (becomes 0).
2. If I XOR all the numbers together, the pairs will find each other 
   and cancel out, no matter where they are in the array.
3. The only number that won't become 0 is the one that only appears once.
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        
        // Walk through the array and "clash" the numbers together
        for (int x : nums) {
            // The XOR operator (^) does the magic here
            result = result ^ x;
        }
        
        // After all the pairs have canceled out, only the single one remains
        return result;
    }
};