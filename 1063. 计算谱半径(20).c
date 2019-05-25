#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a,b;
	int c;
	int max=-1;
	int i;
	for(i=0;i<n;i++){
		scanf("%d %d",&a,&b);
		c=a*a+b*b;
		if(c>max)
			max=c;
	}
	printf("%0.2lf",sqrt(max));
	return 0;
}
