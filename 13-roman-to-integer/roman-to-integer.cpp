class Solution {
public:
    int romanToInt(string s) {
        // Step 1: Map symbols to values
        unordered_map<char, int> m = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int total = 0;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            // Step 2: Look at the current and the next value
            int currentVal = m[s[i]];
            
            // Step 3: Check if we are at the end or if current is smaller than next
            if (i + 1 < n && currentVal < m[s[i+1]]) {
                // Example: IV -> -1 + 5 = 4
                total -= currentVal;
            } else {
                // Example: VI -> 5 + 1 = 6
                total += currentVal;
            }
        }
        
        return total;
    }
};