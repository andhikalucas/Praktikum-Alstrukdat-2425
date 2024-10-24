#include <stdio.h>

const int MOD = 1e9+7;

int main() {
    int n;
    scanf("%d", &n); 
    int grid[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    // DP table to store the number of ways to reach each cell
    int ways[n][n]; 

    // Initialize the DP table as all 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ways[i][j] = 0;
        }
    }

    // There's 1 way to start at (0, 0) if it's not blocked
    if (grid[0][0] == 0) {
        ways[0][0] = 1;
    }

    // Fill the DP table
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) { // Only proceed if the current cell is not blocked
                // Add ways from the cell above (i-1, j) if it exists
                if (i > 0) {
                    ways[i][j] += ways[i-1][j];
                    ways[i][j] %= MOD;
                }
                // Add ways from the cell to the left (i, j-1) if it exists
                if (j > 0) {
                    ways[i][j] += ways[i][j-1];
                    ways[i][j] %= MOD;
                }
            }
        }
    }

    // Output the number of ways to reach the bottom-right corner (n-1, n-1)
    printf("%d\n", ways[n-1][n-1]);

    return 0;
}
