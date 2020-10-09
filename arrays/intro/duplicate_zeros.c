#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

void shiftRight(int*, int, int);
void printArrayElements(int*, int);
void duplicateZeros(int*, int);

int* initializeArray() {
  int* arr = (int*)malloc(SIZE * sizeof(int));
  arr[0] = 1;
  arr[1] = 0;
  arr[2] = 2;
  arr[3] = 3;
  arr[4] = 0;
  arr[5] = 4;
  arr[6] = 5;
  arr[7] = 0;
  return arr;
}

int main() {
  int* arr = initializeArray();
  printArrayElements(arr, SIZE);
  duplicateZeros(arr, SIZE);
  printArrayElements(arr, SIZE);

  free(arr);
}

void duplicateZeros(int* arr, int arrSize) {
  for (int i = 0; i <= arrSize - 2; i++) {
    if (arr[i] == 0) {
      shiftRight(arr, arrSize, i + 1);
      arr[i + 1] = 0;
      i++;
    }
  }
}

void shiftRight(int* arr, int arrSize, int i) {
  for (int j = arrSize - 1; j > i; j--) {
    arr[j] = arr[j - 1];
  }
}

void printArrayElements(int* A, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
}