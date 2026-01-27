class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int i = 0; 
        int j = 0; 

       
        while (i < word1.length() && j < word2.length()) {
            result += word1[i]; 
            result += word2[j]; 
            i++;
            j++;
        }

        // If word1 is longer, add the remaining characters
        while (i < word1.length()) {
            result += word1[i];
            i++;
        }

        // If word2 is longer, add the remaining characters
        while (j < word2.length()) {
            result += word2[j];
            j++;
        }

        return result;
    }
};