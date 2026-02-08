class Solution {
public:

/*
# in this problem we will do 3 checks 
1.Do we have the same length ? if not return false
2. Do we have the same chars in both words , freqs can be diff but the chars must exist in both words
3. Sort the freqs and if both words freqs does not match then return false 

-- Here we are converting a b c to our array index such 0 - > a , 1->b ..... 
so while we check (freq1[i] > 0 && freq2[i] == 0) it means we check does this word '0' exists in both words or not


*/
    bool closeStrings(string word1, string word2) {
        // Step 1: If they aren't the same length, they can't be close.
        if (word1.length() != word2.length()) return false;

        // freq1[0] stores count of 'a', freq1[1] stores 'b', etc.
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for (char c : word1) freq1[c - 'a']++;
        for (char c : word2) freq2[c - 'a']++;

        // Step 2: The "Existence" Check (Checking the letters themselves)
        for (int i = 0; i < 26; i++) {
            // Logic: "If one word has letter 'i' but the other DOESN'T"
            // We don't care about the count here, just if count > 0.
            if ((freq1[i] > 0 && freq2[i] == 0) || (freq2[i] > 0 && freq1[i] == 0)) {
                return false; 
            }
        }

        // Step 3: The "Frequency Bundle" Check (Checking the numbers)
        // We sort them to see if the SET of numbers is identical.
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        // Does [0,0...,1,2,3] == [0,0...,1,2,3]?
        return freq1 == freq2;
    }
};