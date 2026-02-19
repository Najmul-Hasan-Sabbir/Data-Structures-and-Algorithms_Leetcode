/* My intuition:
1. To get to the current step, I must have come from either the 
   step right below it (1 jump) or two steps below it (2 jumps).
2. So, the number of ways to get HERE is just the sum of the ways 
   to get to those two previous spots.
3. This is exactly like the Fibonacci sequence!
n= (n-1)+(n-2)

*/

class Solution {
public:
    int climbStairs(int n) {
        // Handle the simplest cases first, cause for 1 should be 1 and for 2 should be 2 
        if (n <= 2) return n;

        // I'll create an array to "remember" the ways for each step.
        // I need n+1 size so I can use the index to match the step number.
        vector<int> dp(n + 1);

        // I know these two for a fact:
        dp[1] = 1; // 1 way to reach step 1 (1)
        dp[2] = 2; // 2 ways to reach step 2 (1+1 or 2)

        // Now I'll start from step 3 and build up to n
        for (int i = 3; i <= n; i++) {
            // The ways to reach 'i' is the sum of ways for the two steps before it
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        // Return the final result for the top step
        return dp[n];
    }
};