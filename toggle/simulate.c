#include <math.h>
#include "mt19937ar.h"
#include "simulate.h"
#define PI 3.141592654


double unifrnd(double a,double b){
	return ((b-a)*genrand_real3() + a);
}

int sample(double *probs, int n){
    double cumsum = 0;
    int i;
    double p = unifrnd(0.0, 1.0);
    for (i = 0; i < n; i++){
        cumsum += probs[i];
        if (p <= cumsum){
            return(i);
        }
    }
}

double randn(){
	double u1, u2;
	u1 = unifrnd(0.0,1.0); u2 = unifrnd(0.0,1.0);
	return(sqrt(-2*log(u1))*cos(2*PI*u2));
}

double normrnd(double mu, double sd){
	return(mu + sd*randn());
}

double exprnd(double rate){
    return(-log(unifrnd(0.0, 1.0))/rate);
}


double gamrnd(double alpha, double theta) {
    double d,c,x,v,u,a;
    if (alpha < 1){
        a = alpha+1;
    }else{
        a = alpha;
    }
    d=a-1.0/3.0; c=1./sqrt(9*d);
    while(1){
        do {
            x = randn(); v=1.0+c*x; v=v*v*v;
        }while(v<=0.0);
        u=unifrnd(0.0, 1.0);
        if( u<1.0-0.0331*(x*x)*(x*x) ) break;
        if( log(u)<0.5*x*x+d*(1.0-v+log(v)) ) break;
    }
    if (alpha < 1){
        return d*v*theta*pow(unifrnd(0.0,1.0),1.0/alpha);
    }else{
        return d*v*theta;
    }
}

int binornd(int N, double p){
    int i, y=0;
    for (i=1; i<=N; i++){
        if (unifrnd(0,1) < p){
            y++;
        }
    }   
    return(y);
}

int poissrnd(double lambda){
    double p, cumsum;
    int factorial = 1, i=0;
    p = unifrnd(0.0,1.0);
    cumsum = exp(-lambda);
    while(1){
        if (p <= cumsum){
            return(i);
        }
        i++;
        factorial = factorial*i;
        cumsum += pow(lambda,i)*exp(-lambda)/(factorial);
    }
}

