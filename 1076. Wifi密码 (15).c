#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	int i,j,l=0;
	char ans,c,tf;
	int a[n];
	for(i=0;i<n;i++){
		for(j=0;j<4;j++){
			scanf("%c%c%c",&ans,&c,&tf);
			getchar();
			if(tf=='T'){
				a[l++]=ans-'A';
			}
		}
	}
	for(i=0;i<l;i++){
		printf("%d",a[i]+1);
	}
	return 0;
}
