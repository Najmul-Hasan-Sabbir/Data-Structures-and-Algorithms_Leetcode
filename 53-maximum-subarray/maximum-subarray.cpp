class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        


int max_sum=nums[0];
int current=0;


for(int i=0; i<nums.size(); i++){

current=max(nums[i], current+nums[i]);

max_sum=max(max_sum, current);


}

return max_sum;

    }
};