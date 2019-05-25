#include<stdio.h>
#include<math.h>

int b[11000];

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
	int m,n;
	scanf("%d %d",&m,&n);
	int i,j;
	int cnt=1;
	for(i=2;;i++){
		if(IsPrime(i)){
			b[cnt++]=i;
		}
		if(cnt==n+1) break;
	}
	for(i=m,j=1;i<=n;i++){
		if(j%10!=0){
			if(i!=n){
				printf("%d ",b[i]);
			}
			else{
				printf("%d",b[i]);
			}
		}
		else{
			printf("%d\n",b[i]);
		}
		j++;
	}
	return 0;
}
