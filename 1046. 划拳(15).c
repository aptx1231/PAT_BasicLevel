#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int i=0;
	int a[101],b[101],a1[101],b1[101];
	int cnta=0,cntb=0;
	while(n--){
		scanf("%d %d %d %d",&a[i],&a1[i],&b[i],&b1[i]); 
		if((a[i]+b[i])==a1[i]&&(a[i]+b[i])!=b1[i]){
			cnta++;
		}
		else if((a[i]+b[i])!=a1[i]&&(a[i]+b[i])==b1[i]){
			cntb++;
		}
		i++;
	}
	printf("%d %d",cntb,cnta);
	return 0;
} 
