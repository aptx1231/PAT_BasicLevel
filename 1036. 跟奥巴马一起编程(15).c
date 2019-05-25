#include<stdio.h>

int main()
{
	int n;
	char c;
	scanf("%d %c",&n,&c);
	
	double f=n*0.5;
	int b=(int)f;
	int l;
	if(f-b<1e-9){
		l=b;
	}
	else{
		l=b+1;
	}
	//printf("%d",l);
	
	int i;
	for(i=0;i<n;i++){
		printf("%c",c);
	} 
	printf("\n");
	int num=l-2;
	while(num--){
		printf("%c",c);
		for(i=1;i<n-1;i++){
			printf(" ");
		}
		printf("%c\n",c);
	}
	for(i=0;i<n;i++){
		printf("%c",c);
	} 
	printf("\n");
	return 0;
} 
