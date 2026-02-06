class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> hash_map;  
        
        // Step 1: Count frequencies
        for(int i = 0; i < n; i++) {
            hash_map[arr[i]]++;
        }
        
        // Step 2: Check if frequencies are unique
        unordered_set<int> is_seen;
        for(auto& pair : hash_map) { 
            int frequency = pair.second;
            
            if(is_seen.count(frequency) > 0) {
                return false;  // Duplicate frequency found
            }
            is_seen.insert(frequency);
        }
        
        return true;
    }
};