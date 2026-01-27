/*
Simple Dry run: 

Example:
str1 = "ABABAB" (Length = 6)
str2 = "ABAB" (Length = 4)
Step 1: The Concatenation Check 
We check if 
str1 + str2 == str1 + str2 

str1 + str2 = "ABABAB" + "ABAB" = "ABABABABAB"
str2 + str1 = "ABAB" + "ABABAB" = "ABABABABAB"
Result: They are identical! 
This proves that both strings are built from the same repeating pattern.
 If they weren't (e.g., if str2 was "CODE"), the concatenation would fail, and we'd return an empty string.
 Step 2: The Math GCDNow we find the Greatest Common Divisor of the lengths.Length_1 = 6 
Length_2 = 4
 GCD(6, 4) = 2
 Step 3: Extract the ResultWe take the prefix of str1 using the GCD length we just found (2).str1.substr(0, 2) 
  "AB"   Final Answer: "AB"
*/

class Solution {
public:

    string gcdOfStrings(string str1, string str2) {
        // Step 1: Check if a common divisor even exists
        if (str1 + str2 != str2 + str1) {
            return "";
        }

        // Step 2: Find the GCD of the two lengths
        int gcdLength = gcd(str1.length(), str2.length());

        // Step 3: The result is the prefix of that length
        return str1.substr(0, gcdLength);
    }
};


