/*The functions implemented in this file calculate the solution of the linear system of equations A * x=b
through the so-called LU decomposition employed, for example, in LAPACK dgesv function (see https://netlib.org/lapack/explore-html-3.6.1/d7/d3b/group__double_g_esolve_ga5ee879032a8365897c3ba91e3dc8d512.html).
This implementation was used to remove the need for LAPACK in the GRFolres code. It turns out that this algorithm is faster than LAPACK's one.
The solution is found through the following steps:
1. decompose A into the format A = L * U (where L is lower triangular and U is upper triangular). This is the so-called LU decomposition
2. solve A * y = b for y using forward substitution - y is stored in b
3. solve A * x = y for x using back substitution - in the calculation we use b in place of y 
(allowed due to the fact that we store y in b in the previous step); then the solution x is stored in b.
Notice that due to this "storing" strategy (which saves a few floating point operations), the variables x and y need not be defined in the code below.*/

#ifndef LINEARSOLVE_HPP_
#define LINEARSOLVE_HPP_

typedef double data_t;

void LU_decompose(const int& N, data_t *A) {
   for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
         *(A+j*N+i) /= *(A+i*N+i);
         for (int k = i + 1; k < N; k++) {
            *(A+j*N+k) -= *(A+j*N+i) * (*(A+i*N+k));
         }
      }
   }
}

void forward_substitution(const int& N, const data_t *L, data_t *b) {
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < i; j++) {
         *(b+i) -= *(L+i*N+j) * (*(b+j));
      }
   }
}

void back_substitution(const int& N, const data_t *U, data_t *b) {
   for (int i = N - 1; i >= 0; i--) {
      for (int j = i + 1; j < N; j++) {
         *(b+i) -= *(U+i*N+j) * (*(b+j));
      }
      *(b+i) /= *(U+i*N+i);
   }
}

//Solves the linear system A*x=b and updates b with the solution
void solve_linear_system(const int& N, data_t *A, data_t *b) {

   LU_decompose(N,A);
   forward_substitution(N,A,b);
   back_substitution(N,A,b);

}


#endif // LINEARSOLVE_HPP_
