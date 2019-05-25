#include<stdio.h>

int main()
{
	int a[10],b[60];
	int i,j,p=0;
	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
		for(j=0;j<a[i];j++){
			b[p++]=i;
		}
	}
	for(i=0;i<p;i++){
		if(b[i]){
			printf("%d",b[i]);
			b[i]=10;
			break;
		}
	}
	for(i=0;i<p;i++){
		if(b[i]!=10){
			printf("%d",b[i]);
		}
	}
	return 0;
}
