/* My intuition:
1. I need to compare every row with every column.
2. Since I might have multiple identical rows, I'll store each row's 
   frequency in a map.
3. Then, I'll build each column one by one and check if that exact 
   column "pattern" exists in my row map.
4. If it exists, the number of pairs it forms is equal to the number of 
   times that row appeared.
*/

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int count = 0;
        
        // Step 1: Create a map to store the frequency of each row
        // Key: The row (vector), Value: How many times it appeared
        map<vector<int>, int> rowMap;
        
        // Step 2: Fill the map with rows
        for (int i = 0; i < n; i++) {
            rowMap[grid[i]]++; 
        }
        
        // Step 3: Extract each column and check against the map
        for (int j = 0; j < n; j++) {
            vector<int> currentColumn;
            
            // Collect elements for the j-th column
            for (int i = 0; i < n; i++) {
                currentColumn.push_back(grid[i][j]);
            }
            
            // Step 4: If this column matches a row we've seen, 
            // add the frequency of that row to our total count.
            if (rowMap.find(currentColumn) != rowMap.end()) {
                count += rowMap[currentColumn];
            }
        }
        
        return count;
    }
};