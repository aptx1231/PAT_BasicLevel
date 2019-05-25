#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	char c;
	scanf("%c",&c);
	int a[1000];
	int i;
	a[1]=1;
	for(i=2;;i++){
		a[i]=2*(2*i-1)+a[i-1];
		if(a[i]>=n)
			break;
	}
	if(a[i]>n) i--;
	
	int j,k,k0;
	for(j=0;j<(i-1);j++){
		for(k=0;k<(2*i-1)-j;k++){
			if(k<j) printf(" "); 
			else printf("%c",c);
		}
		printf("\n");
	}
	for(j=0;j<=(i-1);j++){
		if(j<i-1) printf(" ");
		else printf("%c\n",c);
	}
	for(j=i-2;j>=0;j--){
		for(k=0;k<(2*i-1)-j;k++){
			if(k<j) printf(" "); 
			else printf("%c",c);
		}
		printf("\n");
	}
	
	printf("%d",n-a[i]);
	return 0;
} 
