// Write a C program to implement iterative and recursive binary search algorithms. Define and use a 
// macro to compare two integers in your program. 
#include <stdio.h>

#define COMPARE(a, b) ((a) == (b) ? 0 : ((a) < (b) ? -1 : 1))

// Function prototypes
int iterativeBinarySearch(int arr[], int size, int target);
int recursiveBinarySearch(int arr[], int left, int right, int target);

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Enter the number to search: ");
    scanf("%d", &target);

    // Iterative binary search
    int result = iterativeBinarySearch(arr, size, target);
    if (result != -1)
        printf("Iterative: Element found at index %d\n", result);
    else
        printf("Iterative: Element not found\n");

    // Recursive binary search
    result = recursiveBinarySearch(arr, 0, size - 1, target);
    if (result != -1)
        printf("Recursive: Element found at index %d\n", result);
    else
        printf("Recursive: Element not found\n");

    return 0;
}

// Iterative binary search
int iterativeBinarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = COMPARE(arr[mid], target);

        if (cmp == 0)
            return mid;
        else if (cmp < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Recursive binary search
int recursiveBinarySearch(int arr[], int left, int right, int target) {
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;
    int cmp = COMPARE(arr[mid], target);

    if (cmp == 0)
        return mid;
    else if (cmp < 0)
        return recursiveBinarySearch(arr, mid + 1, right, target);
    else
        return recursiveBinarySearch(arr, left, mid - 1, target);
}
// Enter the number to search: 10
// Iterative: Element found at index 4
// Recursive: Element found at index 4
