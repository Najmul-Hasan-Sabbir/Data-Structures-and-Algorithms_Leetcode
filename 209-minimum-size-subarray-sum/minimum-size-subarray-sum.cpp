class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
/*
steps:
1. our main goal is to get the minimum len for the target 
2. initilize the min_len=INT_MAX, left=0, curr_sum=0
3. just do a running sum and with a while loop check that if the sum is > the target then inside the while loop shrink it (remove from left index) and also deduct the left index val from the curr_sum until it becomes smaller then the target and always update the min_len 
4. in the end check for the 0 case that if the min_len== INT_MAX then return O else print the min_len

*/

int n=nums.size();
int current_sum=0;
int left=0;
int min_len=INT_MAX;


for(int r=0; r<n; r++){

    current_sum+=nums[r];



while(current_sum>=target){

min_len=min(min_len, r-left+1);

current_sum-=nums[left];

left++;

}


}

return (min_len==INT_MAX)? 0: min_len;

    }
};