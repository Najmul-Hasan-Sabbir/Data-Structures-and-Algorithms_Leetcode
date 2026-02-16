class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        /*
        
         intuition:

        1. We want to remove minimum intervals,
           which means we want to keep maximum non-overlapping ones.

        2. The best greedy strategy:
           always keep the interval that ends earliest.

        3. So we sort by end time.

        4. Then we iterate:
           - If current overlaps with previous → remove it
           - Else → keep it and update previous
        */

        if(intervals.size() == 0) return 0;

        // Sort by ending time
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });

        int remove = 0;
        int prevEnd = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++) {

            // Overlap detected
            if(intervals[i][0] < prevEnd) {
                remove++;
            }
            else {
                // No overlap, keep it
                prevEnd = intervals[i][1];
            }
        }

        return remove;
    }
};
