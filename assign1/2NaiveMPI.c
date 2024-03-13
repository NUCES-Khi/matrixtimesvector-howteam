#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

void make_array() {
    srand(time(NULL));
    FILE *ptr;
    ptr = fopen("128.txt", "w");
    for (int i = 0; i < 128 * 128; ++i) fprintf(ptr, "%d ", rand() % 100);
    fclose(ptr);
    ptr = fopen("256.txt", "w");
    for (int i = 0; i < 256 * 256; ++i) fprintf(ptr, "%d ", rand() % 100);
    fclose(ptr);
}

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    make_array();
    int matrix_size;
    if (rank == 0) {
        matrix_size = 128;
    } else {
        matrix_size = 256;
    }

    int matrix[matrix_size][matrix_size];
    int vector[matrix_size];
    int product[matrix_size];

    FILE *ptr;
    if (rank == 0) {
        ptr = fopen("128.txt", "r");
    } else {
        ptr = fopen("256.txt", "r");
    }

    for (int i = 0; i < matrix_size; i++) {
        for (int j = 0; j < matrix_size; j++) {
            int temp;
            fscanf(ptr, "%d", &temp);
            matrix[i][j] = temp;
        }
    }
    fclose(ptr);

    for (int i = 0; i < matrix_size; i++) {
        vector[i] = rand() % 100;
    }

    double start_time = MPI_Wtime();

    for (int i = 0; i < matrix_size; i++) {
        int sum = 0;
        for (int j = 0; j < matrix_size; j++) {
            sum += matrix[i][j] * vector[j];
        }
        product[i] = sum;
    }

    double end_time = MPI_Wtime();

    if (rank == 0) {
        printf("Time taken: %lf seconds\n", end_time - start_time);
    }

    MPI_Finalize();
    return 0;
}
