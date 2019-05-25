#include<stdio.h>

int main()
{
	int a[1010]={0};
	int n;
	scanf("%d",&n);
	int queue,num,score;
	int max=-1,k;
	while(n--){
		scanf("%d-%d %d",&queue,&num,&score);
		a[queue]+=score;
		if(a[queue]>max){
			max=a[queue];
			k=queue; 
		}
	}
	printf("%d %d",k,max);
	return 0;
}
