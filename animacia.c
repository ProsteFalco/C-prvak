#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>


#define ROWS 20
#define COLM 70
#define CHARACTER 'O'

char array[ROWS][COLM];
int characterHight = 1;
int characterWidht = 1;
int hightIndex = -1;
int widhtIndex = 1;

int main(){
    
    srand(time(0));
    characterHight = rand() % (ROWS - 1) + 1;
    characterWidht = rand() % (COLM - 1) + 1;

    switch(rand() % 2){
        case 0:hightIndex = 1;
                break;
        case 1:hightIndex = -1;
                break;
    }

    switch(rand() % 2){
        case 0:widhtIndex = 1;
                break;
        case 1:widhtIndex = -1;
                break;
    }
 
    while(1){

        if(characterHight == 1 || characterHight == ROWS - 2){
            hightIndex *= -1;
        }
        if(characterWidht == 1 || characterWidht == COLM - 2){
            widhtIndex *= -1;
        }
        
        characterHight += hightIndex;
        characterWidht += widhtIndex; 
        for(int r = 0; r < ROWS; r++){
        for(int c = 0; c < COLM; c++){
            if(c == 0 || r == 0 || c == COLM -1 || r == ROWS -1){
                array[r][c] = '#';
            }
            else if(c == characterWidht && r == characterHight){
                array[r][c] = CHARACTER;
            }
            else{
                array[r][c] = ' ';
            }
        }
    }
        for(int r = 0; r < ROWS; r++){
        for(int c = 0; c < COLM; c++){
            printf("%c", array[r][c]);
        }
        printf("\n");
        }
        usleep(50*1000);
        

    }
    
    return 0;
}




