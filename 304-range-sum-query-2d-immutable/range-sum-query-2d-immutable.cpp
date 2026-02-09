class NumMatrix {
public:
    // prefixSum[i][j] stores the sum of all elements from (0,0) to (i-1, j-1)
    vector<vector<int>> prefixSum;

    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;

        int rows = matrix.size();
        int cols = matrix[0].size();

        // Step 1: Initialize the prefix matrix with size (rows + 1) x (cols + 1)
        // The extra row and column at index 0 remain as 0s (our safety buffer).
        prefixSum.assign(rows + 1, vector<int>(cols + 1, 0));

        // Step 2: Fill the prefixSum matrix
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                // We take the current value from matrix
                int currentValue = matrix[i - 1][j - 1];

                // Add the area directly above it
                int aboveArea = prefixSum[i - 1][j];

                // Add the area directly to the left
                int leftArea = prefixSum[i][j - 1];

                // Subtract the diagonal area that was added twice
                int doubleAddedOverlap = prefixSum[i - 1][j - 1];

                prefixSum[i][j] = currentValue + aboveArea + leftArea - doubleAddedOverlap;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        // Step 3: Use the inclusion-exclusion principle to find the target area
        
        // Total area from (0,0) to the bottom-right of our target
        int totalRect = prefixSum[row2 + 1][col2 + 1];

        // The area above our target that we don't want
        int topSection = prefixSum[row1][col2 + 1];

        // The area to the left of our target that we don't want
        int leftSection = prefixSum[row2 + 1][col1];

        // The top-left corner that was subtracted twice by topSection and leftSection
        int doubleSubtractedCorner = prefixSum[row1][col1];

        return totalRect - topSection - leftSection + doubleSubtractedCorner;
    }
};