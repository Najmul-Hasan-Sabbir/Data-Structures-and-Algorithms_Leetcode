class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;
        string currentStr = "";
        string tempK = ""; // Our "bucket" to collect digit characters

        for (char c : s) {
            if (isdigit(c)) {
                // If we see '1', then '2', tempK becomes "12"
                tempK += c;
            } 
            else if (c == '[') {
                // Now that we hit '[', we convert the whole "12" string to the int 12
                numStack.push(stoi(tempK));
                strStack.push(currentStr);
                
                // Reset our buckets for the next layer
                currentStr = "";
                tempK = "";
            } 
            else if (c == ']') {
                int repeatCount = numStack.top();
                numStack.pop();
                
                string lastStr = strStack.top();
                strStack.pop();
                
                string repeated = "";
                for (int i = 0; i < repeatCount; i++) {
                    repeated += currentStr;
                }
                currentStr = lastStr + repeated;
            } 
            else {
                // Just a normal letter like 'a' or 'b'
                currentStr += c;
            }
        }

        return currentStr;
    }
};