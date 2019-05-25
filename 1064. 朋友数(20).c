#include<stdio.h>

int c[100];

int main()
{
	int n,t,i,cnt=0;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&t);
		int sum=0;
		while(t>0){
			sum+=t%10;
			t/=10;
		}
		c[sum]=1;
	}
	for(i=0;i<100;i++){
		if(c[i]){
			cnt++;
		}
	}
	printf("%d\n",cnt);
	for(i=0;i<100&&cnt>0;i++){
		if(c[i]){
			if(cnt>1)
				printf("%d ",i);
			else
				printf("%d",i);
			cnt--;
		}
	}
	return 0;
}
