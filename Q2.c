/*
2. In the experiments thereafter, using “-O3” option (or standard compiler
optimization with compiler other than gcc) when compiling the code. Implement the
original code of matrix multiplication, vary the array size from N = 16 to 4096
(doubling the value of N each time). When does the program execution time
increase sharply? What’s the relationship between the cache size of your computer
and the array size around the jump point?
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <time.h>
int main()
{
int N; //N x N matrix
for (int N=16; N<4097; N=N*2)
{
//memory allocation for first, second and result matrix
int **mat1 = (int **)malloc(N * sizeof(int*));
for(int m = 0; m < N; m++) mat1[m] = (int *)malloc(N * sizeof(int));
int **mat2 = (int **)malloc(N * sizeof(int*));
for(int m = 0; m < N; m++) mat2[m] = (int *)malloc(N * sizeof(int));
int **mat_res = (int **)malloc(N * sizeof(int*));
for(int m = 0; m < N; m++) mat_res[m] = (int *)malloc(N * sizeof(int));
//creation of matrices, taking random elements between 1 to 100 (optional)
for(int i=0; i<N; i++)
{
for(int j=0; j<N; j++)
{
mat1[i][j] = rand() % 101;
mat2[i][j] = rand() % 101;
}
}
printf("\nFor size:%d\t", N);
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
printf("Matrix multiplication without blocking: time taken:%f", time_taken);
free(mat1);
free(mat2);
free(mat_res);
}
return 0;
}
