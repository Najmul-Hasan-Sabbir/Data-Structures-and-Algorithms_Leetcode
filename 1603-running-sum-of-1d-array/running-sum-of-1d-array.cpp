class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {

        int n=nums.size();

        //vector<int>prefix_sum(n+1);
        
       // prefix_sum[0]=0;



        for(int i=1; i<n; i++){
           
         //  prefix_sum[i+1]=prefix_sum[i]+nums[i];
             
             nums[i]=nums[i]+nums[i-1];

        }
return nums;

    }
};