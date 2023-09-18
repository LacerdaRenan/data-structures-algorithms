#include<stdio.h>
#include<stdlib.h>

/**
 * Renan Lacerda, Software Engineering Student at University of Brasilia, Brazil.
 * The merge function is responsible for joining two sorted arrays into one efficiently.
 * Its complexity is O(N), where N is the sum of the two array sizes.
 * This implementation of the merge function requires two arrays, which i called arr1 and arr2
 * and its sizes, which i calles arr1Size and arr2Size.
*/
int *merge(int *arr1, int arr1Size, int *arr2, int arr2Size);

int main(int argc, char **argv) {
    int arr1[] = { 6, 7, 8, 9 };
    int arr2[] = { 1, 2, 3, 4, 5 };

    int *merged = merge(arr1, 4, arr2, 5);

    for (int i=0; i<9; printf("%i ", merged[i++])); // 1 2 3 4 5 6 7 8 9
    printf("\n");

    int arr3[] = { 10, 11, 12 };

    int *merged2 = merge(arr3, 3, merged, 9);


    for (int i=0; i<12; printf("%i ", merged2[i++])); // 1 2 3 4 5 6 7 8 9 10 11 12
    printf("\n");
    return 0;
}

int *merge(int *arr1, int arr1Size, int *arr2, int arr2Size) {
    int arr1Counter=0, arr2Counter=0, mergedArrCounter=0;
    int *merged = malloc((arr1Size+arr2Size)*sizeof(int));

    while (arr1Counter<arr1Size && arr2Counter<arr2Size) {
        if (arr1[arr1Counter]<arr2[arr2Counter]) merged[mergedArrCounter++]=arr1[arr1Counter++];
        else merged[mergedArrCounter++]=arr2[arr2Counter++];
    }

    // In the case that one array has a larger size, we just copy the remaining content to the merged array.
    while (arr1Counter<arr1Size) merged[mergedArrCounter++]=arr1[arr1Counter++];
    
    while (arr2Counter<arr2Size) merged[mergedArrCounter++]=arr2[arr2Counter++];

    return merged;
}