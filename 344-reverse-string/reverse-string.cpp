/* My intuition:
1. I'll put one finger at the start and one finger at the end.
2. I'll swap the characters under my fingers.
3. Move my fingers closer to each other and repeat.
4. When my fingers meet in the middle, I'm done!
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;


        while (left < right) {
            // Standard swap logic
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;

            // Move the left finger forward and the right finger backward
            left++;
            right--;
        }
    }
};