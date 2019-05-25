#include<stdio.h>

int main()
{
	int n;
	long long a,b,c;
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++){
		scanf("%lld %lld %lld",&a,&b,&c);
		if(a+b-c>0){
			printf("Case #%d: true\n",i);
		}
		else{
			printf("Case #%d: false\n",i);
		}
	}
	return 0;
}
