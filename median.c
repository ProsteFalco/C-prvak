#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void bubbleSort(int * array, int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(array[j+1] < array[j]){
                int tmp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = tmp;
            }
        }
    }
}


int main() {
    
    int userInput;
    int nums[200];
    int sizeOfArray = 0;
        
    while(1){
        
        scanf("%d", &userInput);
        
        if(userInput == -1){
            break;
        }
        nums[sizeOfArray] = userInput;
        sizeOfArray++;
    }
    
    bubbleSort(nums, sizeOfArray);
    if((sizeOfArray % 2) == 1){
        printf("Median: %d", nums[(sizeOfArray / 2)]);
    }
    else{
        printf("Median: %d", ((nums[(sizeOfArray / 2)] + nums[(sizeOfArray / 2) - 1]) / 2));
    }
    

    return 0;
}