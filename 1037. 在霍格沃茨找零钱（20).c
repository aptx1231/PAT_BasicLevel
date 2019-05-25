#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a1,a2,b1,b2,c1,c2;
	scanf("%d.%d.%d %d.%d.%d",&a1,&b1,&c1,&a2,&b2,&c2);
	int s1,s2;
	s1=a1*17*29+b1*29+c1;
	s2=a2*17*29+b2*29+c2;
	if(s1>s2) printf("-");
	
	int gap=abs(s2-s1);
	int a3,b3,c3;
	c3=gap%29;
	a3=gap/17/29;
	b3=(gap-c3-a3*17*29)/29;
	printf("%d.%d.%d",a3,b3,c3);
	return 0;
}
