#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<omp.h>

void make_array(){
     srand(time(NULL));
     FILE *ptr;
     ptr = fopen("128.txt","w");
     for(int i=0;i<128*128;++i) fprintf(ptr,"%d ", rand()%100);
     fclose(ptr);
     ptr = fopen("256.txt","w");
     for(int i=0;i<256*256;++i) fprintf(ptr,"%d ", rand()%100);
     fclose(ptr);
}

int main(){
    make_array();
    int matrix1[128][128], matrix2[128][128], product[128][128];
    FILE *ptr;
    ptr = fopen("128.txt","r");
    for(int i=0;i<128;i++){
        for(int j=0;j<128;j++){
            int temp;
            fscanf(ptr,"%d",&temp);
            char t = fgetc(ptr);
            matrix1[i][j]=temp;
            matrix2[i][j]=temp;
            product[i][j]=0;
         }
     }

    fclose(ptr);
    double time = omp_get_wtime();
    #pragma omp parallel for
    for (int i = 0; i < 128; i++) {
        for (int j = 0; j < 128; j++) {
            int sum = 0;
            for (int k = 0; k < 128; k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            product[i][j] = sum;
        }
    }
    
   printf("Time taken for 128x128 matrix: %lf\n", omp_get_wtime()-time);
   int mat1[256][256], mat2[256][256], prod[256][256];
   ptr = fopen("256.txt","r");
   for(int i=0;i<256;i++){
       for(int j=0;j<256;j++){
           int temp;
           fscanf(ptr,"%d",&temp);
           char t = fgetc(ptr);
           mat1[i][j]=temp;
           mat2[i][j]=temp;
           prod[i][j]=0;
        }
    }

  fclose(ptr);
  time = omp_get_wtime();
  #pragma omp parallel for
  for(int i = 0; i < 256; i++) {
      for(int j = 0; j < 256; j++) {
          int sum = 0;
          for(int k = 0; k < 256; k++) {
              sum += mat1[i][k] * mat2[k][j];
          }
          prod[i][j] = sum;
       }
    }
    
   printf("Time taken for 256x256 matrix: %lf\n", omp_get_wtime()-time);
}
