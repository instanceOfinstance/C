#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find minimum of three numbers
int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

// Function to calculate Levenshtein distance between two strings
int levenshteinDistance(char *str1, char *str2) {
    int m = strlen(str1);
    int n = strlen(str2);
    
    // Create a 2D array to store distances
    int dp[m + 1][n + 1];
    
    // Initialize the array
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0) dp[i][j] = j; // Insert j characters to match empty string str1
            else if (j == 0) dp[i][j] = i; // Insert i characters to match empty string str2
            else if (str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = 1 + min(dp[i - 1][j],      // Deletion
                                     dp[i][j - 1],      // Insertion
                                     dp[i - 1][j - 1]); // Substitution
        }
    }
    
    return dp[m][n];
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    // Open the first file
    FILE *file1 = fopen(argv[1], "r");
    if (!file1) {
        perror("Error opening file 1");
        return 1;
    }

    // Open the second file
    FILE *file2 = fopen(argv[2], "r");
    if (!file2) {
        perror("Error opening file 2");
        fclose(file1);
        return 1;
    }

    // Read content of file 1
    fseek(file1, 0, SEEK_END);
    long fsize1 = ftell(file1);
    fseek(file1, 0, SEEK_SET);
    char *content1 = (char *)malloc(fsize1 + 1);
    fread(content1, fsize1, 1, file1);
    fclose(file1);
    content1[fsize1] = '\0';

    // Read content of file 2
    fseek(file2, 0, SEEK_END);
    long fsize2 = ftell(file2);
    fseek(file2, 0, SEEK_SET);
    char *content2 = (char *)malloc(fsize2 + 1);
    fread(content2, fsize2, 1, file2);
    fclose(file2);
    content2[fsize2] = '\0';

    // Calculate Levenshtein distance
    int distance = levenshteinDistance(content1, content2);

    // Output the Levenshtein distance
    printf("Levenshtein Distance between %s and %s: %d\n", argv[1], argv[2], distance);

    // Free allocated memory
    free(content1);
    free(content2);

    return 0;
}
