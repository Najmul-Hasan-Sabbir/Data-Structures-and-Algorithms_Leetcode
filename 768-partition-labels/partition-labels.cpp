class Solution {
public:
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