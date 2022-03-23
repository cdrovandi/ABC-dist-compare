
#include <mex.h>
#include "mt19937ar.h"
#include "simulate.h"
#include <math.h>
#include <sys/types.h>

void mexFunction(int nlhs, mxArray *plhs[ ],
        int nrhs, const mxArray *prhs[ ])
{                                          
    
    int i,j,c,  T = 300, C = 2000;
    double Pmove, Pbirth, q;
    double *theta, *y_u, *y_v;
    double *u, *v;
    
    init_genrand(time(NULL)*getpid());
    
    u = malloc(T*sizeof(double));
    v = malloc(T*sizeof(double));
    
    
    theta = mxGetPr(prhs[0]); // [mu(0), sigma(1), gamm(2), a_u(3), beta_u(4), a_v(5), beta_v(6)]
    
    
    // Assign for the output
    plhs[0] = mxCreateDoubleMatrix(C,1, mxREAL);
    y_u = mxGetPr(plhs[0]);  // for gene u
    plhs[1] = mxCreateDoubleMatrix(C,1, mxREAL);
    y_v = mxGetPr(plhs[1]);  // for gene v
    
    //srand (time(NULL));
    
    for (c=0; c<C; c++ )
    {
        u[0] = 10;
        v[0] = 10;
        for (j=1; j < T; j++)
        {
            u[j] = u[j-1] + theta[3]/(1+ pow(v[j-1],theta[4]))- 1 -0.03*u[j-1] + 0.5*normrnd(0,1) ;
            v[j] = v[j-1] + theta[5]/(1+ pow(u[j-1],theta[6]))- 1 - 0.03*v[j-1] + 0.5*normrnd(0,1) ;
            if (u[j]<1){
                u[j] = 1;
            }
            if (v[j]<1) {
                v[j] = 1;
            }
        }
        
        y_u[c] = u[T-1] + theta[0]+ theta[0]*theta[1]*normrnd(0,1)/pow(u[T-1],theta[2]);
        y_v[c] = v[T-1] +theta[0]+ theta[0]*theta[1]*normrnd(0,1)/pow(v[T-1],theta[2]);
        if (y_u[c]<1){
            y_u[c] = 1;
        }
        if (y_v[c]<1) {
            y_v[c] = 1;
        }
        
    }
    free(u);
    free(v);
}










