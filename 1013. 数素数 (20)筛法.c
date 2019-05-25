#include<stdio.h>
#include<math.h>

int p[110000];
int prime[12000];

int main()
{
	int m,n;
	scanf("%d %d",&m,&n);
	int i,j,l=0,x,high;
	int cnt=1;
	
	for(i=2;;i++){
		if(p[i]==0){
			prime[l++]=i;
			if(l>n) break;
			if(n*n>110000) high=110000;
			else high=n*n;
			for(x=2;x*i<high;x++){
				p[x*i]=1;
			}
		}
	}
	
	for(i=m-1,j=1;i<n;i++){
		if(j%10!=0){
			if(i!=n-1){
				printf("%d ",prime[i]);
			}
			else{
				printf("%d",prime[i]);
			}
		}
		else{
			printf("%d\n",prime[i]);
		}
		j++;
	}
	return 0;
}
