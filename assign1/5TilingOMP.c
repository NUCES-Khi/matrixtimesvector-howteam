#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <omp.h>

int main()
{
    int matrix1[128][128], matrix2[128][128], product[128][128];
    FILE *ptr;
    ptr = fopen("128tiling.txt", "w");
    for (int i = 0; i < 128; i++)
    {
        for (int j = 0; j < 128; j++)
        {
            int temp;
            fscanf(ptr, "%d", &temp);
            char t = fgetc(ptr);
            matrix1[i][j] = temp;
            matrix2[i][j] = temp;
            product[i][j] = 0;
        }
    }
    fclose(ptr);
    double time = omp_get_wtime();
#pragma omp parallel sections num_threads(4)
    {

#pragma omp section
        {
            for (int i = 0; i < 128 / 4; ++i)
            {
                for (int j = 0; j < 128 / 4; ++j)
                {
                    for (int k = 0; k < 128 / 4; ++k)
                        product[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
#pragma omp section
        {
            for (int i = (128 / 4); i < 128 / 2; ++i)
            {
                for (int j = 0; j < 128 / 2; ++j)
                {
                    for (int k = 0; k < 128; ++k)
                        product[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
#pragma omp section
        {
            for (int i = (128 / 2); i < 3 * 128 / 4; ++i)
            {
                for (int j = 0; j < 128; ++j)
                {
                    for (int k = 0; k < 128; ++k)
                        product[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
#pragma omp section
        {
            for (int i = 3 * 128 / 4; i < 128; ++i)
            {
                for (int j = 0; j < 128; ++j)
                {
                    for (int k = 0; k < 128; ++k)
                        product[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
    }
    printf("Time taken for 128x128 matrix: %lf\n", omp_get_wtime() - time);
    int mat1[256][256], mat2[256][256], prod[256][256];
    ptr = fopen("256tiling.txt", "w");
    for (int i = 0; i < 256; i++)
    {
        for (int j = 0; j < 256; j++)
        {
            int temp;
            fscanf(ptr, "%d", &temp);
            char t = fgetc(ptr);
            mat1[i][j] = temp;
            mat2[i][j] = temp;
            prod[i][j] = 0;
        }
    }
    fclose(ptr);
    time = omp_get_wtime();
#pragma omp parallel sections num_threads(4)
    {

#pragma omp section
        {
            for (int i = 0; i < 256 / 4; ++i)
            {
                for (int j = 0; j < 256; ++j)
                {
                    for (int k = 0; k < 256; ++k)
                        prod[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }
#pragma omp section
        {
            for (int i = (256 / 4); i < 256 / 2; ++i)
            {
                for (int j = 0; j < 256; ++j)
                {
                    for (int k = 0; k < 256; ++k)
                        prod[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }
#pragma omp section
        {
            for (int i = (256 / 2); i < 3 * 256 / 4; ++i)
            {
                for (int j = 0; j < 256; ++j)
                {
                    for (int k = 0; k < 256; ++k)
                        prod[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }
#pragma omp section
        {
            for (int i = 3 * 256 / 4; i < 256; ++i)
            {
                for (int j = 0; j < 256; ++j)
                {
                    for (int k = 0; k < 256; ++k)
                        prod[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }
    }
    printf("Time taken for 256x256 matrix: %lf\n", omp_get_wtime() - time);
}
