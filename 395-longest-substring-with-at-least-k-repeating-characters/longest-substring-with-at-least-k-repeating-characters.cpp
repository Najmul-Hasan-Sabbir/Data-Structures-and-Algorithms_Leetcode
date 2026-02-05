class Solution {
public:
/*
APPROACH: Fixed Unique Count Sliding Window

Problem: We need longest substring where EVERY character appears ≥ k times.
Challenge: Sliding window tricky - don't know when to shrink/expand.

Solution: Try all possible unique character counts (1 to 26):
1. For each target unique count, find longest substring with:
   - EXACTLY 'target' unique characters
   - ALL 'target' characters appear ≥ k times
2. Use sliding window for each fixed target
3. Return maximum across all targets

Why it works: Optimal substring must have X unique chars (1≤X≤26).
We don't know X, so we try all possibilities!
*/


    int longestSubstring(string s, int k) {
        int max_len = 0;
        int n = s.length();

        // Try for windows containing 1 unique char, then 2, ..., up to 26
     for (int currUniqueTarget = 1; currUniqueTarget <= 26; currUniqueTarget++)    {
            unordered_map<char, int> freq;
            int i = 0, uniqueCount = 0, atLeastKCount = 0;

            for (int j = 0; j < n; j++) {
                // Expand
                if (freq[s[j]] == 0) 
                {
                    uniqueCount++;
                 }

                freq[s[j]]++;
                
                if (freq[s[j]] == k) 
                {
                 atLeastKCount++;
                }
                

                // Shrink
                while (uniqueCount > currUniqueTarget) {
                    if (freq[s[i]] == k){
                     atLeastKCount--;
                    }
                     
                    freq[s[i]]--;
                    if (freq[s[i]] == 0) {
                        uniqueCount--;
                        freq.erase(s[i]);
                    }
                    i++;
                }

                // Check: Do we have the right number of uniques, 
                // and do all of them meet the K requirement?
                if (uniqueCount == currUniqueTarget && uniqueCount == atLeastKCount) {
                    max_len = max(max_len, j - i + 1);
                }
            }
        }
        return max_len;
    }
};