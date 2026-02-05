class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
       long long max_sum=0;
       long long curr_sum=0;
       int n=nums.size();
       
       unordered_map<int,int>hash_table;


       for(int i=0; i<n; i++){
// STEP 1: ALWAYS ADD the current element (Expanding the window)
        
        curr_sum+=nums[i];
        hash_table[nums[i]]++;
// STEP 2: REMOVE THE TAIL (Shrinking the window)
// We only do this once the scout 'i' has moved past the first 'k' elements.
 // If k=3 and i=3, we need to remove the element at index 0.

        if(i>=k){

            int tail_val=nums[i-k];
            curr_sum-=tail_val;
            hash_table[tail_val]--;
               // CRITICAL: map.size() counts KEYS. 
                // If a number appears 0 times, its KEY must be deleted 
                // so that map.size() accurately reflects DISTINCT elements.
               if(hash_table[tail_val]==0){
            hash_table.erase(tail_val);
        }

        }
         // STEP 3: CHECK THE RESULT
            // 'i >= k - 1' ensures our window has finally reached size K.
            // 'freq.size() == k' ensures all K elements in the window are unique.
         if(i>=k-1 && hash_table.size()==k){
            max_sum=max(curr_sum, max_sum);
         }
     

       }

return max_sum;
    }
};