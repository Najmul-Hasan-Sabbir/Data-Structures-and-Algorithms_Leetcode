class Solution {
public:


/*
My intuitio:
1. I will make an Map /vector to keep track of all the 26 chars 
2. Then i will do a check from right to left and store their last occourences in the map 
3. then i will do a check from left to right and now with every check i will check their last occour val and keep the max val as our end for this partition 
4. and the end val== i that means our this partition is done , we will move to next partition 





*/
    vector<int> partitionLabels(string s) {
        vector<int> last(26, 0);
        
        // Step 1: Store the last index of each character
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }
        
        vector<int> result;
        int start = 0;
        int end = 0;
        
        // Step 2 & 3: Traverse and find partitions
        for (int i = 0; i < s.size(); i++) {
            // Greedily expand the boundary of the current partition
            end = max(end, last[s[i] - 'a']);
            
            // If the current index matches the furthest reach, close the chunk
            if (i == end) {
                result.push_back(end - start + 1);
                start = i + 1;
            }
        }
        
        return result;
    }
};