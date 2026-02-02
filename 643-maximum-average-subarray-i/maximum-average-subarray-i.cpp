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


double max_sum=0;

   double curr_sum=0;
for(int i=0; i<k; i++){

        curr_sum+=nums[i];
}
max_sum=curr_sum;

for(int i=k; i<nums.size(); i++){

    curr_sum=curr_sum-nums[i-k];
     curr_sum+=nums[i];

if(curr_sum>max_sum){

    max_sum=curr_sum;

}


}


double avg=max_sum/k;

return avg;
    }
};