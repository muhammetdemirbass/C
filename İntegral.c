#include <stdio.h>
#include <math.h>

double fx(double);
double Integral (double (*f)(double),double , double , int );

int main()
{
	
	int i;
	for(i=50;i<100;i=i+10)
	{
	printf("solution is x= %.4lf for n=%d \n",Integral(fx,0,2,i),i);	
	}
	return 0;
}

double fx(double x)
{
	return sin(x)+pow(x,2);
}

double Integral (double (*f)(double),double a, double b, int n)
{
	int i;
	double xk, xk1,step,sum=0.0;
	
	step=(b-a)/n;
	
	xk=a;
	 for (i=0;i<n;i++){
	 	xk1=xk+step;
	 	sum=(f(xk1)+f(xk))*step/2;
	 	xk=xk1;
	 }
	 return sum;
}

