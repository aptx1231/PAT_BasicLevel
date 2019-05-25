#include<stdio.h>
#include<string.h>
#include<math.h>

struct per{
	char award[20];
	int Is;
}a[10001];

int IsPrime(int n)
{
	int i;
	for(i=2;i<sqrt(n)+1;i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}

int main()
{
	int n,t,i;
	scanf("%d",&n);
	for(i=0;i<=10000;i++){
		a[i].Is=0;
	}
	for(i=1;i<=n;i++){
		scanf("%d",&t);
		a[t].Is=1;
		if(i==1){
			strcpy(a[t].award,"Mystery Award");
		}
		else{
			if(IsPrime(i)){
				strcpy(a[t].award,"Minion");
			}
			else{
				strcpy(a[t].award,"Chocolate");
			}
		}
	}
	
	int num,tmp;
	scanf("%d",&num);
	while(num--){
		scanf("%d",&tmp);
		if(a[tmp].Is==1){
			printf("%04d: %s\n",tmp,a[tmp].award);
			a[tmp].Is=2;
		}
		else if(a[tmp].Is==0){
			printf("%04d: %s\n",tmp,"Are you kidding?");
		}
		else if(a[tmp].Is==2){
			printf("%04d: %s\n",tmp,"Checked");
		}
	}
	return 0;
}
