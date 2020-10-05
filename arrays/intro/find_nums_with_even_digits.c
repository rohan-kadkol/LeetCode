#include<stdio.h>

int findNumbers(int *, int);

int main() {
  int numbers[] = {212, 393, 1, 222, 953, 31113, 3492, 23411, 9280, 131134138};
  printf("# of nums with even digits = %d\n", findNumbers(numbers, 10));
}

int findNumbers(int* nums, int numsSize){
    int numEven = 0;
    for (int i=0; i<numsSize; i++) {    
        int numDigits = 1;
        int number = nums[i]/10;
        while(number) {
            numDigits++;
            number /= 10;
        }
        numEven += numDigits % 2 == 0;
    }
    
    return numEven;
}