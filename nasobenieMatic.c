#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
    
    int fstRows;
    int fstColumns;
    int scndRows;
    int scndColumns;
    int fst = 0;
    int scnd = 0;
    int num = 0;
    int mun = 0;

    FILE * input_file_1 = fopen(argv[1], "r");
    FILE * input_file_2 = fopen(argv[2], "r");
    FILE * output_file = fopen(argv[3], "w");

    fseek(input_file_2, 0, SEEK_SET);    
    fseek(input_file_1, 0, SEEK_SET);
    fseek(output_file, 0 , SEEK_SET);

    fscanf(input_file_1, "%d", &fstRows); 
    fscanf(input_file_1, "%d", &fstColumns); 

    fscanf(input_file_2, "%d", &scndRows); 
    fscanf(input_file_2, "%d", &scndColumns); 

    fprintf(output_file, "%d %d\n",fstRows, scndColumns);


    int * fstMatica = malloc(sizeof(int) * fstRows * fstColumns);
    int * scndMaticaInput = malloc(sizeof(int) * scndRows * scndColumns);
    int * scndMaticaTransp = malloc(sizeof(int) * scndRows * scndColumns);

    int * resultMatica = malloc(sizeof(int) * fstRows * scndColumns);
    
    while (1)
    {   
        if(fscanf(input_file_1, "%d", &num) == EOF){
             break;
        }

        fstMatica[fst] = num;
        fst++;
    }
    while (1)
    {   
        if(fscanf(input_file_2, "%d", &mun) == EOF){
             break;
        }

        scndMaticaInput[scnd] = mun;
        scnd++;
    }
    
    int index = 0;
    for (int l = 0; l < scndColumns; l++)
    {
        for (int k = 0; k < scndRows; k++)
        {
            scndMaticaTransp[index] = scndMaticaInput[l +(k * scndColumns)];
            index++;
        }
    }

    int indexR = 0;

    for(int x = 0; x < fstRows; x++){
        for(int i = 0; i < scndColumns; i++){
            for(int j = 0; j < scndRows; j++){
                resultMatica[indexR] += fstMatica[j + (x * scndRows)] * scndMaticaTransp[j + (i * scndRows)];    
            }
            indexR++;
        }
    }
    
    for(int i = 0; i < fstRows; i++){
        for(int j = 0; j < scndColumns; j++){
            fprintf (output_file,"%d ", resultMatica[j + (i * scndColumns)]);
        }
        fprintf(output_file,"\n");
    }

    fclose(input_file_1);
    fclose(input_file_2);
    fclose(output_file);
    free(fstMatica);
    free(scndMaticaInput);
    free(scndMaticaTransp);
    free(resultMatica);

    return 0;
}

