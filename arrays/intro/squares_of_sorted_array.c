#include <stdio.h>
#include <stdlib.h>

#define SIZE 6

int* sortedSquares(int*, int, int*);
void quickSort(int*, int, int);
int partition(int*, int, int);
void swap(int*, int, int);
void printArrayElements(int*, int);

int* initializeArray() {
  int *A = malloc(SIZE*sizeof(int));
  A[0] = -90;
  A[1] = -13;
  A[2] = -9;
  A[3] = -2;
  A[4] = 16;
  A[5] = 64;
  printArrayElements(A, SIZE);
}

int main() {
  int* A = initializeArray();
  int *size = (int*) malloc(sizeof(int));

  int *output = sortedSquares(A, SIZE, size);
  printArrayElements(A, SIZE);
  
  free(output);
  free(A);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* A, int ASize, int* returnSize){
    int* output = malloc(ASize * sizeof(int));
    
    for (int i=0; i<ASize; i++) {
        output[i] = A[i]*A[i];
    }
    
    quickSort(output, 0, ASize-1);
    return output;
}

void quickSort(int *A, int start, int end) {
    if (end <= start) return;
    
    int mid = partition(A, start, end);
    
    quickSort(A, start, mid-1);
    quickSort(A, mid+1, end);
}

int partition(int *A, int start, int end) {
    int pivot = end;
    int i = start-1;
    
    for (int j=start; j<end; j++) {
        if (A[j] < A[pivot]) {
            swap(A, ++i, j);
        }
    }
    
    swap(A, ++i, pivot);
    return i;
}

void swap(int *A, int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void printArrayElements(int *A, int size) {
  for (int i=0; i<size; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
}