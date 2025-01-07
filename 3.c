// Write a C program to perform pattern matching using KMP Algorithm. (Print the failure function of a 
// pattern and display whether match is found or not).
#include <stdio.h>
#include <string.h>

void computeFailureFunction(char *pattern, int *failure, int m);
int KMPMatch(char *text, char *pattern);

int main() {
    char text[100], pattern[50];
    int match;

    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the pattern: ");
    scanf("%s", pattern);

    match = KMPMatch(text, pattern);

    if (match != -1)
        printf("Pattern found at index %d\n", match);
    else
        printf("Pattern not found\n");

    return 0;
}

// Function to compute the failure function of the pattern
void computeFailureFunction(char *pattern, int *failure, int m) {
    int i = 1, j = 0;
    failure[0] = 0;

    while (i < m) {
        if (pattern[i] == pattern[j]) {
            j++;
            failure[i] = j;
            i++;
        } else {
            if (j != 0) {
                j = failure[j - 1];
            } else {
                failure[i] = 0;
                i++;
            }
        }
    }

    printf("\nFailure Function: ");
    for (i = 0; i < m; i++) {
        printf("%d ", failure[i]);
    }
    printf("\n");
}

// Function to perform KMP pattern matching
int KMPMatch(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int failure[m];
    int i = 0, j = 0;

    computeFailureFunction(pattern, failure, m);

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            return i - j; // Match found, return the starting index
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0)
                j = failure[j - 1];
            else
                i++;
        }
    }

    return -1; // Match not found
}
