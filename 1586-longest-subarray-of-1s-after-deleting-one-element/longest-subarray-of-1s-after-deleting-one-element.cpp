class Solution {
public:
    int longestSubarray(vector<int>& nums) {
         
         int num_of_zeros=0;
         int max_length=0;

         for(int j=0,i=0; j<nums.size(); j++){
         

         if(nums[j]==0){
            num_of_zeros++;

         }
           

           while(num_of_zeros>1){
            if(nums[i]==0){
                num_of_zeros--;
            }
            i++;
           }
            // j - i + 1 would be the total elements.
             
          max_length=max(max_length, j-i+1);


         }
     

    


  return max_length-1;

    }
};