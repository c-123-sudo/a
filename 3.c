// Write a C program to perform pattern matching using KMP Algorithm. (Print the failure function of a 
// pattern and display whether match is found or not).
#include <stdio.h>
#include <string.h>

void computeFailureFunction(char* pattern, int* failure) {
    int i = 1, j = 0;
    int m = strlen(pattern);
    failure[0] = 0;
    
    while (i < m) {
        if (pattern[i] == pattern[j]) {
            failure[i] = j + 1;
            i++;
            j++;
        }
        else if (j > 0) {
            j = failure[j - 1];
        }
        else {
            failure[i] = 0;
            i++;
        }
    }
}

void KMPSearch(char* text, char* pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int failure[m];
    
    computeFailureFunction(pattern, failure);
    
    printf("Failure Function: ");
    for(int i = 0; i < m; i++) {
        printf("%d ", failure[i]);
    }
    printf("\n");
    
    int i = 0, j = 0;
    int found = 0;
    
    while (i < n) {
        if (text[i] == pattern[j]) {
            if (j == m - 1) {
                printf("Pattern found at position: %d\n", i - j);
                found = 1;
                j = failure[j];
            }
            i++;
            j++;
        }
        else if (j > 0) {
            j = failure[j - 1];
        }
        else {
            i++;
        }
    }
    
    if (!found) {
        printf("Pattern not found in text\n");
    }
}

int main() {
    char text[100], pattern[100];
    
    printf("Enter text: ");
    scanf("%s", text);
    printf("Enter pattern: ");
    scanf("%s", pattern);
    
    KMPSearch(text, pattern);
    
    return 0;
}
