#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int i,t,sum=0;
	for(i=0;i<n;i++){
		scanf("%d",&t);
		sum+=t;
	}
	sum*=(n-1);
	sum*=11;
	printf("%d",sum);
	return 0;
}
