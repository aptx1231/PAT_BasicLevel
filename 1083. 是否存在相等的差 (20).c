#include<stdio.h>
#include<stdlib.h>

int num[10009];

int main()
{
	int n;
	scanf("%d",&n);
	int a[n+1];
	int i;
	int max=-1,min=30000;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		num[abs(a[i]-i)]++;
		if(abs(a[i]-i)>max){
			max=abs(a[i]-i);
		}
		if(abs(a[i]-i)<min){
			min=abs(a[i]-i);
		}
	}
	for(i=max;i>=min;i--){
		if(num[i]>1){
			printf("%d %d\n",i,num[i]);
		}
	}
	return 0;
}
