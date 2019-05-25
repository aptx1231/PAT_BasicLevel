#include<stdio.h>
//所有连续序列之和 
int main()
{
	double a[100001];
	int n;
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++){
		scanf("%lf",&a[i]);
	}
	
	//对于a[i]出现的次数：
	//a[i]前边有几个数（包括a[i]）分几种情况，即序列的开头 
	//对于每个开头，a[i]后边有几个数（包括a[i]），就是几种结尾 
	double sum=0.0;
	for(i=1;i<=n;i++){
		sum+=(a[i]*i*(n-i+1));
	}
	printf("%0.2lf",sum);
	return 0;
}
