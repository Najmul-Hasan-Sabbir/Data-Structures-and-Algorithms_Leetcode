class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
    
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        // Step 2: Fixing the first element one by one
        for (int i = 0; i < n - 2; i++) {
            
            // Skipping duplicate values for i
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            // Step 3: Two pointers
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    // Found a valid triplet
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Step 4: Will skip duplicates for left
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    
                    // Skipping duplicates for right
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    // Moving both pointers
                    left++;
                    right--;
                }
                else if (sum < 0) {
                    // Sum too small → increase it
                    left++;
                }
                else {
                    // Sum too large → decrease it
                    right--;
                }
            }
        }
        
        return result;
    }
};
