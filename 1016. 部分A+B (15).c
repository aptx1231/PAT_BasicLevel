#include<stdio.h>
#include<string.h>
int main()
{
	char a[20];
	char b[20];
	int n1,n2;
	scanf("%s %d %s %d",a,&n1,b,&n2);
	int i;
	int cnt1=0,cnt2=0;
	for(i=0;i<strlen(a);i++){
		if(a[i]==n1+'0'){
			cnt1++;
		}
	}
	for(i=0;i<strlen(b);i++){
		if(b[i]==n2+'0'){
			cnt2++;
		}
	}
	long long a1=0;
	for(i=0;i<cnt1;i++){
		a1=a1*10+n1;
	}
	long long b1=0;
	for(i=0;i<cnt2;i++){
		b1=b1*10+n2;
	}
	printf("%lld",a1+b1);
}
