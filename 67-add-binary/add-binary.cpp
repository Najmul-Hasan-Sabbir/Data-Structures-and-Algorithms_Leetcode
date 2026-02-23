class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.length() - 1; // Pointer for string a
        int j = b.length() - 1; // Pointer for string b
        int carry = 0;

        // Keep going as long as there's a digit left or a carry to add
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) {
                sum += a[i] - '0'; // Convert char '1' or '0' to int
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }

            // If sum is 2, result is 0 and carry is 1.
            // If sum is 3, result is 1 and carry is 1.
            result += (sum % 2) + '0'; 
            carry = sum / 2;
        }

        // Because we added bits from right to left, the string is backwards
        reverse(result.begin(), result.end());
        return result;
    }
};