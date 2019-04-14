/*
 * Tema 2 ASC
 * 2019 Spring
 * Catalin Olaru / Vlad Spoiala
 */
#include "utils.h"

/*
 * Add your optimized implementation here
 */
double* my_solver(int N, double *A, double* B) {
	printf("OPT SOLVER\n");

	double *temp1 = (double *)calloc(N * N, sizeof(double));
	double *temp2 = (double *)calloc(N * N, sizeof(double));

	double *res = (double *)calloc(N * N, sizeof(double));

	double *At = (double *)calloc(N * N, sizeof(double));
	double *Bt = (double *)calloc(N * N, sizeof(double));

	int index = -1;
	int i, j, k;

	for (i = 0; i < N; ++i) {
		double * ai = &A[i * N];
		double * bi = &B[i * N];
		for (j = 0; j < N; ++j) {
			index = j * N + i;
		
			At[index] = *ai;
			Bt[index] = *bi;

			ai++;
			bi++;
		}
	}
	for (i = 0; i < N; ++i) {
		double *pAt_orig = &At[i * N];
		double *pBt_orig = &Bt[i * N];

		for (j = 0; j < N; ++j) {
			register double suma1 = 0.0;
			register double suma2 = 0.0;

			//double *pA = pA_orig;
			double *pAt = pAt_orig;
			double *pBt = pBt_orig;
			double *pB = &B[j];
			double *pA = &A[j];
			//double *pBt = &Bt[j];

			index = i * N + j;

			for (k = 0; k < N; ++k) {
				suma1 += *pAt * *pB;
				suma2 += *pBt * *pB;

				pAt++;
				pBt++;

				pA += N;
				pB += N;
			}
			temp1[index] = suma1;
			temp2[index] = suma2;
		}
	}

	free(At);
	free(Bt);

	for (i = 0; i < N; ++i) {
		double * t1_index = &temp1[i * N];
		double *t2_index = &temp2[i * N];

		for (j = 0; j < N; ++j) {
			*t1_index += i > j ? (-(*t1_index)) : *t2_index;
			
			t1_index++;
			t2_index++;
		}
	}

	for (i = 0; i < N; ++i) {
		double *orig_p1 = &temp1[i * N];
		for (j = 0; j < N; ++j) {

			double *p1 = orig_p1;
			double *p2 = &temp1[j];
			register double suma = 0.0;

			for (k = 0; k < N; ++k) {
				suma += *p1 * *p2;

				p1++;
				p2 += N;
			}

			index = i * N + j;
			res[index] = suma;
		}
	}

	free(temp1);
	free(temp2);

	return res;
}