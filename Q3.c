/*
3. Implement the blocking method, set the blocking factor B to 8, and vary the array
size as above (from N = 16 to 4096). Compare the execution time with and without
blocking. Based on the results, what’s your suggestion on applying the blocking
method?
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <time.h>
int main()
{
int N; //N x N matrix
int B=8;
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
