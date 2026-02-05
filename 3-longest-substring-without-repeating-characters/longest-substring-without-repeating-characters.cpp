class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n=s.length();

        int longest_sub=0;
        int curr_sub=0;

        unordered_map<char, int>freq;

         int count=0;
         int i=0; // The "Anchor" (left side of the window)
        // j is the "Scout" (right side of the window)
        for(int j=0; j<n; j++){
        // STEP 1: Add the current character to the map
           freq[s[j]]++;

      // STEP 2: Check for duplicates
    // If map.size() is less than the number of elements in the window (j - i + 1),
    // it means at least one character is repeated.
          while(freq.size()< (j-i+1)) {
    // Shrink the window from the left
            char tail_char=s[i];
            freq[tail_char]--;
            // STEP 3: The CRITICAL Erase
                // Just like before, we must remove the key if the count hits 0
                // so that freq.size() correctly reflects unique characters.
            if(freq[tail_char]==0){
                freq.erase(tail_char);
            }
            // Moving the anchor forward
             i++;


          }


    // STEP 4: Once the while loop is done, the window is guaranteed 
            // to have only unique characters. Update the record.
         longest_sub=max(longest_sub, (j-i+1));

        }
      


return longest_sub;

    }
};