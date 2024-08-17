#include <iostream>
#include "linearsolve.hpp"

#define GR_SPACEDIM 3

typedef double data_t;

int main () {
	
   const int N = GR_SPACEDIM * (GR_SPACEDIM + 1) / 2 + 2;
	data_t LHS[N][N],RHS[N];

   //initialise matrix of coefficients (LHS) and vector of coefficients (RHS) with some non-trivial values for thorough testing
	for (int i=0; i<N; i++){
      RHS[i]=i+1;
      printf("RHS[%d]=%lf\n",i,RHS[i]);
		for (int j=0; j<N; j++){
			if (i==j) LHS[i][j]=i+1;
         else if (i!=j && j!=7) LHS[i][j]=i+1-(j+1)+100;
			else LHS[i][j]=0;
			printf("LHS[%d][%d]=%lf\n",i,j,LHS[i][j]);
		}
	}

   //solve linear system LHS*x=RHS and updates RHS with the solution
   solve_linear_system(N,&LHS[0][0],RHS);

   data_t test_sol[N]={0.0354221, 0.0260244, 0.0164329, 0.00664164, -0.00335578, -0.0135659, -0.0239956, 0.398498};

   bool test_failed=false;
   //test and print inverse matrix
   for (int i=0; i<N; i++){
         if (!test_failed) 
            printf("RHS[%d]=%.8lf\n",i,RHS[i]);
            if (abs(RHS[i]-test_sol[i])>1.0e-6){
               test_failed=true;
               printf("TEST FAILED\n");
      }
   }
   if (!test_failed) printf("TEST SUCCEEDED\n");



	return 0;
}
