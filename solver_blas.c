/*
 * Tema 2 ASC
 * 2019 Spring
 * Catalin Olaru / Vlad Spoiala
 */
#include "utils.h"

/* 
 * Add your BLAS implementation here
 */
#include "cblas.h"

double* my_solver(int N, double *A, double *B) {
	printf("BLAS SOLVER\n");
	
	double *temp1 = (double *)calloc(N * N, sizeof(double));
	double *temp2 = (double *)calloc(N * N, sizeof(double));

	double *res = (double *)calloc(N * N, sizeof(double));

	int i, j;

	cblas_dgemm(CblasRowMajor, CblasTrans, CblasNoTrans,
				N, N, N, 1, A, N, B, N, 0, temp1, N);

	cblas_dgemm(CblasRowMajor, CblasTrans, CblasNoTrans,
				N, N, N, 1, B, N, A, N, 0, temp2, N);

	for (i = 0; i < N; ++i)
	{
		double *t1_index = &temp1[i * N];
		double *t2_index = &temp2[i * N];

		for (j = 0; j < N; ++j)
		{
			*t1_index += i > j ? (-(*t1_index)) : *t2_index;

			t1_index++;
			t2_index++;
		}
	}

	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
				N, N, N, 1, temp1, N, temp1, N, 0, res, N);

	free(temp1);
	free(temp2);
	return res;
}
