#include<stdio.h>

int main()
{
	int m,n,min,max,o;
	scanf("%d %d %d %d %d",&m,&n,&min,&max,&o);
	int i,j;
	int a[m][n];
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]>=min&&a[i][j]<=max){
				a[i][j]=o;
			}
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%03d",a[i][j]);
			if(j!=n-1){
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
