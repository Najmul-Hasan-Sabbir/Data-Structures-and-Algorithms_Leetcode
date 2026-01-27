class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        

      int n=nums.size();


      unordered_map<int , int>hash_table;


      for(int i=0; i<n; i++){
        int complement= target- nums[i];

        if(hash_table.find(complement)!=hash_table.end()){

           
            return {hash_table[complement], i};
            break;

        }
        else{

             hash_table[nums[i]] = i; 
        }

       


      }


return {};
    }
};