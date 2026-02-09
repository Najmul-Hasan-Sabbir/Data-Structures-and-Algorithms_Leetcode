class Solution {
public:
/*
 1. We will make a Hash map and use it to store and check our target val 
 2. we will not make any prefix array ,instead we will make a current Sum where we will check the current SUm
 3. Update runningSum += num.
 4.target = runningSum - k , we will check if the target val is present in the map , if found then how many time then increment the count and repeate 
 5. 





*/

    int subarraySum(vector<int>& nums, int k) {
    unordered_map<int , int> seenSum;

    // Must be 1 to count subarrays that start from index 0
    seenSum[0] = 1; 

    int running_sum = 0;
    int count = 0;

    for(int num : nums) {
        running_sum += num;
        int target = running_sum - k;

        // If we have seen (running_sum - k) before, 
        // it means the elements in between sum to k.
        if(seenSum.count(target)){
            count += seenSum[target];
        }

        // Add the current running_sum to our "memory"
        seenSum[running_sum]++;
    }
    return count;
}
};