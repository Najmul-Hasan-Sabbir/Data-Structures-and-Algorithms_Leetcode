class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        /*
       My Intuition:
        1. First check if the total gas available is at least the total cost.
           If not, it is impossible to complete the circle from any station.

        2. If total gas >= total cost, then a solution exists.
           We then use a greedy approach:
           - Keep a running tank of fuel.
           - If at any point tank becomes negative, it means the current
             starting station cannot work.
           - So we reset the start to the next station and reset tank to 0.
        */

        int n = gas.size();
        int total_cost = 0;
        int total_gas = 0;

        // Global feasibility check
        for (int i = 0; i < n; i++) {
            total_cost += cost[i];
            total_gas += gas[i];
        }

        if (total_cost > total_gas) {
            return -1;  // Impossible to complete the circuit
        }

        int start = 0;  // Candidate starting index
        int trunk = 0;  // Current fuel in tank

        // Greedy linear scan
        for (int i = 0; i < n; i++) {
            trunk += gas[i] - cost[i];

            // If fuel becomes negative, current start fails
            if (trunk < 0) {
                start = i + 1;  // Try next station as new start
                trunk = 0;     // Reset fuel
            }
        }

        // This start is guaranteed to work
        return start;
    }
};
