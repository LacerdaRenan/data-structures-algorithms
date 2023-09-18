#include<stdio.h>

/**
 * Renan Lacerda, Software Engineering Student at University of Brasilia, Brazil.
 * The binary search is a supper efficient algorithm that can find any element in the
 * space of O(logN) iterations if the array is sorted. This implementation is using
 * the binary search to show us how many iteractions the algorithm take to find
 * an element and is using the iterative method of the binary search.
*/

int buscaBinaria(int *arr, int sizeOfArray, int element);

int main(int argc, char **argv) {

    int sizeOfArray;
    scanf("%i", &sizeOfArray);

    int arr[sizeOfArray]; // Must be a sorted array
    for (int i=0; i<sizeOfArray; i++) scanf("%i", &arr[i]);
    
    int element;
    scanf("%i",&element);

    printf("%i\n", buscaBinaria(arr, sizeOfArray, element));
    
    return 0;
}


int buscaBinaria(int *arr, int sizeOfArray, int element) {
    int left=0, right = sizeOfArray-1, middle = (right+left)/2, iterations=0;

    while(left<right) {
        iterations++;
        if (arr[middle] == element) return iterations;
        else if (arr[middle] > element) {
            right = middle;
            middle = (right+left)/2;
        }
        else if (arr[middle] < element) {
            left = middle;
            middle = (right+left)/2;
        }
    }

    return -1;
}
