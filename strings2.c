#include <stdio.h>
#include <stdlib.h>

int main (int argc, char ** argv) {
   
    int character;
    int lenghtOfString = 3;
    int helper = 0;
    int lastSymbol = 0;
    char* fileName;
    
    if(argc == 3){
        lenghtOfString = atoi(argv[1]);
        fileName = argv[2];
    }
    else{
        lenghtOfString = 3;
        fileName = argv[1];
    }


    FILE * file = fopen(fileName, "r");
    char * buffer = (char*) malloc(lenghtOfString + 1);

    while (1)
    {
        character = fgetc(file);
        if(character == EOF){
            free(buffer);
            break;
        }
        if(character >= 32 && character <= 126){
            if(helper <= lenghtOfString - 1){
                buffer[helper] = character;
                if(helper == lenghtOfString - 1){
                    buffer[helper+1] = '\0';
                    printf("%s", buffer);
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
    fclose(file);
    return 0;
    


    
   
}