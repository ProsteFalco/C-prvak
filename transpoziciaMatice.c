#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
    
    int rows;
    int columns;
    int i = 0;
    int num = 0;

    FILE * file_1 = fopen(argv[1], "r");
    FILE * file_2 = fopen(argv[2], "w");

    fseek(file_1, 0, SEEK_SET);
    fscanf(file_1, "%d", &rows); 
    fscanf(file_1, "%d", &columns); 
    fprintf(file_2, "%d %d\n",columns, rows);

    int * array = malloc(sizeof(int) * rows * columns);
    
    while (1)
    {   
        if(fscanf(file_1, "%d", &num) == EOF){
             break;
        }

        array[i] = num;
        i++;
    }


    for (int i = 0; i < columns; i++)
    {
        for (int k = 0; k < rows; k++)
        {
            fprintf (file_2,"%d ", array[i +(k * columns)]);
        }

        fprintf(file_2,"\n");
    }
    
    fclose(file_1);
    fclose(file_2);
    free(array);


    return 0;
}

