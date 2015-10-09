#include <stdio.h>
#include <math.h>
#define pi 3.14159

double pulse (double x) {
	if(x>-0.5 && x<0.5)
		return 1;
	return 0;
}
double circle (double x, double r) {
	if(abs(x)<r) 
		return sqrt(pow(r,2)-pow(x,2));
	else 
		return 0;
}
double tri (double x) {
	return fmod(x,2.0);
}
double sinc(double x) {
	if(x==0)
		return 1; //(lim x->0 [sinx/x] =1)
	return sin(x)/x;
}
double f(double x) {
	return sinc(x);
}

int main() {
	double c;
	double x=0;
	printf("# X Y\n");
	for(x=-6; x<6;x+=0.01) {
		//printf("%f %f\n",x,sinc(x));
	}
	for(x=-6; x<6;x+=0.01) {
		double ix;
		c=0;
		for(ix=-6;ix<6;ix+=0.001)
			c=c+(cos(2*pi*x*ix)*f(ix));
		printf("%f %f\n",x,c);
	}
	return 0;
}
