/*
 * Tema 2 ASC
 * 2019 Spring
 * Catalin Olaru / Vlad Spoiala
 */
#include "utils.h"

/*
 * Add your unoptimized implementation here
 */
double* my_solver(int N, double *A, double* B) {
	double *At = (double *)calloc(N * N, sizeof(double));
	double *Bt = (double *)calloc(N * N, sizeof(double));

	int index = -1;
	int index1 = -1;
	int index2 = -1;

	double *temp1 = (double *)calloc(N * N, sizeof(double));
	double *temp2 = (double *)calloc(N * N, sizeof(double));

	double *res = (double *)calloc(N * N, sizeof(double));

	int i, j, k;

	// calculate A^t and B^t
	for ( i = 0; i < N; i++) {
		for ( j = 0; j < N; j++) {
			index1 = i * N + j;
			index2 = j * N + i;

			At[index2] = A[index1];
			Bt[index2] = B[index1];
		}
	}

	// calculate A^t*B and B^t*A
	for ( i = 0; i < N; i++) {
		for ( j = 0; j < N; j++) {
			index = i * N + j;
			for ( k = 0; k < N; k++) {
				index1 = i * N + k;
				index2 = k * N + j;
				
				temp1[index] += At[index1] * B[index2];
				temp2[index] += Bt[index1] * A[index2];
			}
		}
	}

	free(At);
	free(Bt);

	// make temp1 = zerotr(A^tB + B^tA)
	for ( i = 0; i < N; i++) {
		for ( j = 0; j < N; j++) {
			index = i * N + j;
			temp1[index] = i > j ? 0 : temp1[index] + temp2[index];
		}
	}

	index1 = -1;
	index2 = -1;

	// make res = temp1^2
	for ( i = 0; i < N; i++) {
		for ( j = 0; j < N; j++) {
			index = i * N + j;

			for ( k = 0; k < N; k++) {
				index1 = i * N + k;
				index2 = k * N + j;

				res[index] += temp1[index1] * temp1[index2];
			}
		}
	}

	free(temp1);
	free(temp2);

	return res;
}
/*
int main() {
	int N = 4;
	double *temp = (double *)calloc(N * N, sizeof(double));
	double *temp2 = (double *)calloc(N * N, sizeof(double));

	double *res = (double *)calloc(N * N, sizeof(double));

	temp[0] = 2;
	temp[1] = 2;
	temp[2] = 1;
	temp[3] = 7;

	temp[4] = 4;
	temp[5] = 4;
	temp[6] = 2;
	temp[7] = 14;

	temp[8] = 6;
	temp[9] = 6;
	temp[10] = 3;
	temp[11] = 21;

	temp[12] = 8;
	temp[13] = 8;
	temp[14] = 4;
	temp[15] = 28;

	/////////////////////////////////////

	temp2[0] = 0;
	temp2[1] = 6;
	temp2[2] = 3;
	temp2[3] = 21;

	temp2[4] = 0;
	temp2[5] = 4;
	temp2[6] = 2;
	temp2[7] = 14;

	temp2[8] = 0;
	temp2[9] = 10;
	temp2[10] = 5;
	temp2[11] = 35;

	temp2[12] = 0;
	temp2[13] = 8;
	temp2[14] = 4;
	temp2[15] = 28;

	res = my_solver(4, temp, temp2);

	int index = -1;
	int i,j;
	for ( i = 0; i < N; i++) {
		for ( j = 0; j < N; j++) {
			index = i * N + j;
			printf("%lf\t", res[index]);

			if (index % 4 == 3) {
				printf("\n");
			}
		}
	}

	free(res);
	free(temp);

	return 0;
}
*/