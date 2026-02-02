class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        int n=nums.size();
        int left=0;
        int right=n-1;
// first sorting the nums 
         sort(nums.begin(),nums.end());
          int count=0;

         while(left<right){
// now using two pointers to calculate 
// case if sum <k then do l++
// case if sum >k then do r--
// case this means the sum is = k , so do count ++ and l++ r--
         if((nums[left]+nums[right])<k){
            left++;
         }
         else if((nums[left]+nums[right])>k){
         
         right--;

         }
         else{
           
           count++;
           left++;
           right--;

         }




         }

return count;

    }
};