#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    // Input matrix a (n x n)
    int matrix[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Input matrix b (2 x 2)
    int pattern[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &pattern[i][j]);
        }
    }

    int totalMatches = 0; // To count valid matches

    // Loop over all 2x2 submatrices in matrix a
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1; j++) {
            int matchFound = 0; // Flag to check if a match is found

            // Try all 4 rotations of the pattern
            for (int rotation = 0; rotation < 4; rotation++) {
                int validMatch = 1; // Assume the current pattern is a valid match

                // Check if the 2x2 submatrix in 'matrix' matches 'pattern'
                for (int k = 0; k < 2; k++) {
                    for (int l = 0; l < 2; l++) {
                        if (matrix[i + k][j + l] <= pattern[k][l]) {
                            validMatch = 0; // If the matrix value is smaller or equal, it's not a match
                        }
                    }
                }

                // If a valid match is found, increment the count and stop further rotation checks
                if (validMatch) {
                    totalMatches++;
                    matchFound = 1;
                    break;
                }

                // Rotate the pattern 90 degrees clockwise
                int temp = pattern[0][0];
                pattern[0][0] = pattern[1][0];
                pattern[1][0] = pattern[1][1];
                pattern[1][1] = pattern[0][1];
                pattern[0][1] = temp;
            }
        }
    }

    // Output the total number of matches
    printf("%d\n", totalMatches);

    return 0;
}