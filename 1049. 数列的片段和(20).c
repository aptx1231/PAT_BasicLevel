#include<stdio.h>
//������������֮�� 
int main()
{
	double a[100001];
	int n;
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++){
		scanf("%lf",&a[i]);
	}
	
	//����a[i]���ֵĴ�����
	//a[i]ǰ���м�����������a[i]���ּ�������������еĿ�ͷ 
	//����ÿ����ͷ��a[i]����м�����������a[i]�������Ǽ��ֽ�β 
	double sum=0.0;
	for(i=1;i<=n;i++){
		sum+=(a[i]*i*(n-i+1));
	}
	printf("%0.2lf",sum);
	return 0;
}
