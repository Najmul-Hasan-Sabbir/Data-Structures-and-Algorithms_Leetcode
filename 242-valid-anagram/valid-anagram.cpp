/* My intuition:
1. First, check lengths. If they aren't equal, they can't be anagrams!
2. We are using a simple array of size 26 as a "Mini-Hashmap" because we only 
   have lowercase letters. It's faster and uses less memory.
3. String 's' is my "Bank Deposit": For every letter I see, I add 1 to its count.
4. String 't' is my "Withdrawal": For every letter I see, I subtract 1.
5. If the count ever drops below 0, it means string 't' tried to use a letter 
   that string 's' didn't provide. (Like trying to spend money you don't have!)
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        // Step 1: Immediate exit if lengths don't match
        if (s.length() != t.length()) return false;
        
        // Step 2: Create our "Mini-Hashmap" using an array of 26 integers
        int count[26] = {0};
        
        // Step 3: Deposit all letters from string 's'
        for (char c : s) {
            count[c - 'a']++;
        }
        
        // Step 4: Withdraw letters based on string 't'
        for (char c : t) {
            count[c - 'a']--;
            
            /* THE "BANKRUPT" CHECK:
               If the value is -1, it means 't' has a letter that 's' didn't have 
               enough of. Since lengths are equal, if one goes negative, 
               it's game over!
            */
            if (count[c - 'a'] < 0) {
                return false;
            }
        }
        
        // If we survived the loop, everything balanced out to zero perfectly!
        return true;
    }
};