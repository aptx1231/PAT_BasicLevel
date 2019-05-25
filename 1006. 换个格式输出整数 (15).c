#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int a,b,c;
	c=n%10;
	b=n/10%10;
	a=n/100;
	//printf("%d %d %d",a,b,c);
	int i;
	for(i=0;i<a;i++){
		printf("B");
	}
	for(i=0;i<b;i++){
		printf("S");
	}
	for(i=1;i<=c;i++){
		printf("%d",i);
	}
	return 0;
} 
