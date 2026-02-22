/* My Intuition:
1. This is a "find the odd one out" problem. 
2. XOR is perfect here because it acts like a toggle. If I see 'a' twice, 
   the first one turns the bit ON, and the second one turns it OFF.
3. Since 't' has exactly one more character than 's', every character 
   in 's' will find a partner in 't' and cancel out.
4. The added character will be the only one left "ON" at the end.

DRY RUN:
Sum of t:'a' + 'b' + 'c' + 'e'
97 + 98 + 99 + 101 = 395
Sum of s:'a' + 'b' + 'c'
97 + 98 + 99 = 294 
The Difference:395 - 294 = 101
Final Result: (char)101 which is 'e'.

*/

class Solution {
public:
    char findTheDifference(string s, string t) {
        char result = 0;
        
        // XOR all characters in string s
        for (char c : s) {
            result ^= c;
        }
        
        // XOR all characters in string t
        for (char c : t) {
            result ^= c;
        }
        
        // The leftover value is the added character
        return result;
    }
};