/*
1. Implement the original code of matrix multiplication and set the value of N to 1024.
Compile the code using the optimization options “-O0” (no compiler optimization)
and “-O3” (standard compiler optimization) with gcc, respectively. What is the
speedup using “-O3” compared with using “-O0”? If you are using another compiler
other than gcc, use two different optimization options supported by the compiler to
run the experiments, one without any compiler optimization and another with
standard compiler optimization.
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <time.h>
int main()
{
int N = 1024; //N x N matrix
//memory allocation for first, second and result matrix
int **mat1 = (int **)malloc(N * sizeof(int*));
for(int m = 0; m < N; m++) mat1[m] = (int *)malloc(N * sizeof(int));
int **mat2 = (int **)malloc(N * sizeof(int*));
for(int m = 0; m < N; m++) mat2[m] = (int *)malloc(N * sizeof(int));
int **mat_res = (int **)malloc(N * sizeof(int*));
for(int m = 0; m < N; m++) mat_res[m] = (int *)malloc(N * sizeof(int));
//creation of matrices, taking random elements between 1 to 100 (optional)
for(int i=0; i<N; i++){
for(int j=0; j<N; j++){
mat1[i][j] = rand() % 101;
mat2[i][j] = rand() % 101;
}
}
printf("Matrix created.\n");
printf("Matrix size is:%d", N);
int matrix_mult_without_blocking()
{
clock_t start, end;
double time_taken; //time_taken is total cpu time
start = clock();
//original matrix multiplication without blocking
for(int i=0; i<N; i++){
for(int j=0; j<N; j++){
for(int k=0; k<N; k++){
mat_res[i][j] += mat1[i][k]*mat2[k][j];
}
}
}
end = clock();
time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("\nMatrix multiplication without blocking: time taken:%f", time_taken);
return 0;
}
matrix_mult_without_blocking(); //function call
return 0;
}
