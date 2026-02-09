class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int>is_seen;

       int n=nums.size();

        for(int i=0; i<n-1; i++){

        int curr_sum=nums[i]+nums[i+1];
         
         if(is_seen.count(curr_sum)){
            return true;
         }
         is_seen.insert(curr_sum);

        }
        return false;
    }
};