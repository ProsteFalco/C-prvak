#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int main(){
    
    srand(time(0));
    int rn =  (rand() % 100) + 1;
    int upperRange = 100;
    int lowerRange = 0;
    int guess;

    printf("Random:%d\n", rn);
    
    while(1){
        guess = (upperRange + lowerRange) / 2;
        printf("%d\n", guess);
        
        if(guess < rn){
            lowerRange = guess;
        }
        else if(guess > rn){
            upperRange = guess;
        }
        else{
            printf("Hotovo!");
            break;
        }
    }
}