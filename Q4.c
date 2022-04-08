/*
4. Use the blocking method, set the array size N to 2048, and vary the blocking factor B
from 4 to 512 (in power of two only). What is the optimal blocking factor for the
program and what is your suggestion on choosing the blocking factor?
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <time.h>
int main()
{
int N=2048; //N x N matrix
int B;
for (int B=4; B<513; B=B*2)
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
printf("\nFor blocking factor:%d\t", B);
clock_t start, end;
double time_taken; //time_taken is total cpu time
start = clock();
//matrix multiplication with blocking
for (int ii = 0; ii < N; ii+=B)
{
for (int jj = 0; jj < N; jj+=B)
{
for (int kk = 0; kk < N; kk+=B)
{
for (int i = ii; i < ii+B; i++)
{
for (int j = jj; j < jj+B; j++)
{
for (int k = kk; k < kk+B; k++)
{
mat_res[i][j] += mat1[i][k]*mat2[k][j];
}
}
}
}
}
}
end = clock();
time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("Matrix multiplication with blocking: time taken:%f", time_taken);
free(mat1);
free(mat2);
free(mat_res);
}
return 0;
}
