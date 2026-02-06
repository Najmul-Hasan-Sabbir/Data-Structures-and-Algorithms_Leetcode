class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // Convert to sets to remove duplicates
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        
        vector<int> nums1Only, nums2Only;
        
        // Find numbers present ONLY in nums1
        for(int num : set1) {
            // If num is NOT found in set2
            if(set2.find(num) == set2.end()) {
                nums1Only.push_back(num);
            }
        }
        
        // Find numbers present ONLY in nums2
        for(int num : set2) {
            // If num is NOT found in set1  
            if(set1.find(num) == set1.end()) {
                nums2Only.push_back(num);
            }
        }
        
        return {nums1Only, nums2Only};
    }
};