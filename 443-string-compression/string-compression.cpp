class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int read = 0;  // This is my 'explorer'—it looks at every original character
        int write = 0; // This is my 'writer'—it marks where the next compressed part goes

        while(read < n){
            int count = 0;
            // Store the current character because 'read' is about to move away
            char char_val = chars[read];

            // Here I'm checking: "How many of the same characters are in a row?"
            while(read < n && char_val == chars[read]){
                count++; // Found one!
                read++;  // Move explorer to the next one to see if it's the same
            }

            // Always write the character first 
            // Using write++ means: "Put it here, then move the writer forward for the next thing"
            chars[write++] = char_val;

            // Only add a number if there's actually a group (more than 1)
            if(count > 1){
                // Convert the number (like 12) to a string ("12")
                // because I need to write '1' and '2' as separate characters
                string count_string = to_string(count);
               
                for(char c : count_string){
                   // Write each digit of the number one by one 
                   chars[write++] = c;
                }
            }
          
        }

        // 'write' tells me the total length of the compressed part I created
        return write;
    }
};