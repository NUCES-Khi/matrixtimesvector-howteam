#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char *argv[]){
    if(argc !=3 ){
        printf("Usage: %s <matrix_size> <vector_size>\n", argv[0]);
        return 1;
    }

    int matrix_size = atoi(argv[1]);
    int vector_size = atoi(argv[2]);

    if(matrix_size <=0 || vector_size <= 0){
        printf("Invalid input size. Sizes must be greater than 0.\n");
        return 1;
    }

    int *matrix = (int *)malloc(matrix_size * sizeof(int *));
    int *vector = (int *)malloc(vector_size * sizeof(int));
    int *result = (int *)malloc(matrix_size * sizeof(int));

    srand(time(NULL));

    for(int i = 0; i < matrix_size; i++){
        matrix[i] = (int *)malloc(vector_size * sizeof(int));
        for(int j = 0; j < vector_size; j++){
            matrix[i][j] = rand() % 10;
        }
    }

    for(int i = 0; i < vector_size; i++){
        vector[i] = rand() % 10;
    }

    clock_t start_time = clock();
    for(int i = 0; i < matrix_size; i++){
        result[i] = 0;
        for(int j = 0; j < vector_size; j++){
            result[i] += matrix[i][j] * vector[j];
        }
    }

    clock_t end_time = clock();

    double time_taken = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Resulting Vector:\n");
    for(int i = 0; i < matrix_size; i++){
        printf("%d ", result[i]);
    }

    printf("\n");

    printf("Time taken: %f seconds\n", time_taken);

    for(int i = 0; i < matrix_size; i++){
        free(matrix[i]);
    }

    free(matrix);
    free(vector);
    free(result);

    return 0;
}
