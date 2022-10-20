#include <stdio.h>
#include <stdlib.h>


int main(int argc, char ** argv){

    int character;
    int lenghtOfString = 3;
    int helper = 0;
    int lastSymbol = 0;
    
    if(argc > 1){
        lenghtOfString = atoi(argv[1]);
    }
    char * array = (char*) malloc(lenghtOfString + 1 * sizeof(char));
    while(1){
        
        character = getchar();
        if(character == EOF){
            free(array);
            break;
        }
        
        if(character >= 32 && character <= 126){
            if(helper <= lenghtOfString - 1){
                array[helper] = character;
                if(helper == lenghtOfString - 1){
                    array[helper+1] = '\0';
                    printf("%s", array);
                    lastSymbol = 1;
                    
                }
                helper++;
                
                
            }
            else if(helper > lenghtOfString - 1){
                putchar(character);
                lastSymbol = 1;
            }
        }
        else{
            if(lastSymbol){
                printf("\n");
                lastSymbol = 0;
            }
            helper = 0;
        }
        
    }
    
    return 0;
}
