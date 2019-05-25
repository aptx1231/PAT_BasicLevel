#include<stdio.h>
#include<math.h>

int IsPrime(int n)
{
	int i;
	for(i=2;i<=sqrt(n);i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}

int main()
{
	int n;
	scanf("%d",&n);
	int i,p=0;
	int b[n];
	for(i=2;i<=n;i++){
		if(IsPrime(i)){
			b[p++]=i;
		}
	}
	int cnt=0;
	for(i=1;i<p;i++){
		if(b[i]-b[i-1]==2){
			cnt++;
		}
	}
	printf("%d",cnt);
	return 0;
}
