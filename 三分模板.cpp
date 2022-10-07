#include<cstdio>
#include<cmath>
using namespace std;
const double eps=1e-5;
double a,b,c,xx,yy;
double f(double x){
	return sqrt((x-xx)*(x-xx)+(a*x*x+b*x+c-yy)*(a*x*x+b*x+c-yy));
}
int main(){
	scanf("%lf%lf%lf%lf%lf",&a,&b,&c,&xx,&yy);
	double l=-200,r=200;
	while(r-l>eps){
		double lm=l+(r-l)/3,rm=r-(r-l)/3;
		if(f(lm)<f(rm)) r=rm;
		else l=lm;
	}
	printf("%.3lf\n",f(l));
	return 0;
} 
