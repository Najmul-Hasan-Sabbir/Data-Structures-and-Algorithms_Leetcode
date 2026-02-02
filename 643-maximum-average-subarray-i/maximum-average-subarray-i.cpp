class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        


/*
steps:
1. get the first window sum of k 
2. make the MaxSum and keep the first window sum in that MaxSum
3. then we will get the rest of the window one by one ,
- the i will start from k
- we will deduct the [i-k] th val from the windowSum then add nums[i]
4. and always update the maxSum in the global var 

5. at the end just do the avg 




*/




int max_sum=0;
int window_sum=0;
// getting the first window
for(int i=0; i<k; i++){

 
 window_sum+=nums[i];

}

max_sum=window_sum;


// now we will get the rest of the val for the window one by one

for(int i=k; i<nums.size(); i++){


window_sum=window_sum-nums[i-k]+nums[i];


max_sum=max(window_sum, max_sum);


}






return (double)max_sum / k;
    }
};