class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int max_one=0;
         int count=0;
        int n=nums.size();

        for(int i=0; i<n; i++){

           if(nums[i]==0){
            count=0;
           }
           else if(nums[i]==1){
            count++;
           }
           max_one=max(max_one, count);

        }


return max_one;
    }
};