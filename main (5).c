
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubbleSort(char input[]) {
    int arr[100];
    
    int n = 0;
    int swapCounts[100] = {0}; // Initialize swapCounts array to store swap counts for each value
    int totalSwaps = 0;
    
    char inputCpy[100]; 
    for (int i = 0; i < 100; i++) {
        inputCpy[i] = input[i];
    }
    
    // Parse input
    char *token = strtok(inputCpy, ": "); // Split input string by colon and space
    printf("%s bubble sort:\n", token); // Print array name
    
    token = strtok(NULL, ": "); // Get the second part of the string (array elements)
    
    // Parse array elements
    while (token != NULL) {
        arr[n++] = atoi(token); // Convert token to integer and add it to the array
        token = strtok(NULL, " "); // Get next token
    }
    
    int i, j, temp;
    totalSwaps = 0;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                
                // Increment swap count for both elements
                swapCounts[arr[j]]++;
                swapCounts[arr[j+1]]++;
                totalSwaps++; // Increment total swaps
            }
        }
    }
    
    // Print sorted array with swap counts
    for (i = 0; i < n; i++) {
        printf("%d: %d\n", arr[i], swapCounts[arr[i]]);
    }
    
    printf("%d\n", totalSwaps);
}

void selectionSort(char input[]) {
    int arr[100];
    
    int n = 0;
    int swapCounts[100] = {0}; // Initialize swapCounts array to store swap counts for each value
    int totalSwaps = 0;
    
    char inputCpy[100]; 
    for (int i = 0; i < 100; i++) {
        inputCpy[i] = input[i];
    }
    
    // Parse input
    char *token = strtok(inputCpy, ": "); // Split input string by colon and space
    printf("%s selection sort:\n", token); // Print array name
    
    token = strtok(NULL, ": "); // Get the second part of the string (array elements)
    
    // Parse array elements
    while (token != NULL) {
        arr[n++] = atoi(token); // Convert token to integer and add it to the array
        token = strtok(NULL, " "); // Get next token
    }
    
    int i, j, minIndex, temp;
    // Sort
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            // Swap arr[i] and arr[minIndex]
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;

            // Increment swap count for both elements
            swapCounts[arr[i]]++;
            swapCounts[arr[minIndex]]++;
            totalSwaps++; // Increment total swaps
        }
    }
    
    // Print sorted array with swap counts
    for (i = 0; i < n; i++) {
        printf("%d: %d\n", arr[i], swapCounts[arr[i]]);
    }
    
    printf("%d\n", totalSwaps);
}

int main() {
    char input1[100], input2[100];
    
    fgets(input1, sizeof(input1), stdin);
    fgets(input2, sizeof(input2), stdin);
    
    bubbleSort(input1);
    bubbleSort(input2);
    selectionSort(input1);
    selectionSort(input2);
    
    return 0;
}