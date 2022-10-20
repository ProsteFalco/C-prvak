#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv){

    int character;
    int ceasar = 3;
    int helper = 0;
    int lastSymbol = 0;
    char* fileName;
    
    if(argc == 3){
        ceasar = atoi(argv[1]);
        fileName = argv[2];
    }
    else{
        ceasar = 3;
        fileName = argv[1];
    }

    FILE * file = fopen(fileName, "r");

    int dir;
    if(ceasar >= 0){
        dir = ceasar;
    }
    else{
        dir = ceasar * -1;
    }
    
    while (1)
    {
        character = fgetc(file);
        if(character == EOF){
            break;
        }

        if((character >= 65 && character <= 90) || (character >= 97 && character <= 122)){
            for(int i = 0; i < dir; i++){

                if(character >= 65 && character <= 90){
                    
                    if(ceasar >= 0){
                        character++;
                    }
                    else{
                        character--;
                    }

                    if(character < 65){
                        character = 122;
                    }
                    else if(character > 90){
                        character = 97;
                    }
                    else{
                        continue;
                    }
                }
                else if(character >= 97 && character <= 122){
                
                    if(ceasar >= 0){
                        character++;
                    }
                    else{
                        character--;
                    }


                    if(character < 97){
                        character = 90;
                    }
                    else if(character > 122){
                        character = 65;
                    }
                    else{
                        continue;
                    }


                }
            }
            putchar(character);


        }
        else{
            putchar(character);
        }
        

    }
    fclose(file);   

    return 0;
}
