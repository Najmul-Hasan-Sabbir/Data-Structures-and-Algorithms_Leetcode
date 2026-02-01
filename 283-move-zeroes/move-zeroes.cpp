class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int read=0;
        int write=0;

        int n=nums.size();

        for(int read=0; read<n; read++){

         if(nums[read]!=0){
           
           int temp=nums[write];
           nums[write]=nums[read];
           nums[read]=temp;
          
           write++;
         }
         // If it's a zero, the scout (read) just keeps walking, 
            // but the writer (write) stays behind waiting for a number!

        }
       
    }
};