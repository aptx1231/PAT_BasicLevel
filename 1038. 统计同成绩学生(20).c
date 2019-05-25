#include<stdio.h>
int main() 
{
	int a[100001]={0};
	int n;
	int i,t;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&t);
		a[t]++;
	}
	int num;
	scanf("%d",&num);
	while(num--){
		int tmp;
		scanf("%d",&tmp);
		
		if(num!=0){
			printf("%d ",a[tmp]);
		}
		else{
			printf("%d",a[tmp]);
		}
	}
	return 0;
}
