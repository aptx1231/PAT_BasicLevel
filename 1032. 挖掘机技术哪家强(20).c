#include<stdio.h>

int a[100001];
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	int num,score;
	int max=-1;

	for(i=0;i<n;i++){
		scanf("%d %d",&num,&score);
		a[num]+=score;
		if(a[num]>max){
			max=a[num];
		}
	}
	
	for(i=0;i<n;i++){
		if(a[i]==max){
			break;
		}
	}
	printf("%d %d",i,max);
	return 0;
}
