#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int cnt;
	cnt=0;
	while(n!=1){
		if(n&1){
			n=3*n+1;
			n/=2;
			cnt++;
		}
		else{
			n/=2;
			cnt++;
		}
	}
	printf("%d",cnt);
	return 0;
} 
