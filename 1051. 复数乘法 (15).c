#include<stdio.h>
#include<math.h>
int main()
{
	double r1,r2,p1,p2;
	scanf("%lf %lf %lf %lf",&r1,&p1,&r2,&p2);
	double a1,b1,a2,b2;
	a1=r1*cos(p1);
	b1=r1*sin(p1);
	a2=r2*cos(p2);
	b2=r2*sin(p2);
	//printf("%lf %lf %lf %lf\n",a1,b1,a2,b2);
	double a,b;
	a=a1*a2-b1*b2;
	b=a1*b2+a2*b1;
	
	if(a > -0.005 && a < 0.005) a = 0; 
    if(b > -0.005 && b < 0.005) b = 0; 

	if(b<0)
		printf("%0.2lf%0.2lfi\n",a,b);
	else 
		printf("%0.2lf+%0.2lfi\n",a,b);
	
	return 0;
}
