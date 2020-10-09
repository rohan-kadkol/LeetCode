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
  return A;
}

int main() {
  int* A = initializeArray();
  int *size = (int*) malloc(sizeof(int));

  int *output = sortedSquares(A, SIZE, size);
  printArrayElements(output, SIZE);
  
  free(output);
  free(A);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* A, int ASize, int* returnSize){
    int* output = malloc(ASize * sizeof(int));
    int i = 0, j = ASize - 1, k = ASize - 1;

    while (i != j) {
      int leftSq = A[i
      ]*A[i];
      int rightSq = A[j]*A[j];

      if (leftSq > rightSq) {
        output[k--] = leftSq;
        i++;
      } else {
        output[k--] = rightSq;
        j--;
      }
    }
    output[k] = A[i]*A[i]; // As now i == j after the loop

    return output;
}

void printArrayElements(int *A, int size) {
  for (int i=0; i<size; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
}