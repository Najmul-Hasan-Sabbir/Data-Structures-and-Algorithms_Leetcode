class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
   
         int start=0;
         int mid=0;
         int end=n-1;

         while(mid<=end){
          
          if(nums[mid]==0){
            int temp=nums[start];
            nums[start]=nums[mid];
            nums[mid]=temp;
            start++;
            mid++;
          }
          else if(nums[mid]==1){
            mid++;
          }
          else{

            int temp=nums[mid];
            nums[mid]=nums[end];
            nums[end]=temp;
            end--;
            // Reminder: No mid++ here because we must check the new nums[mid]
          }




         }



    }
};