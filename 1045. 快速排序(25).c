#include<stdio.h>
#include<stdlib.h>
//��С�Ҵ�����Ԫ
//��Ԫ���ź��������λ������ͬ��
//ǰ������Ԫ�Ļ� 
//M��С����Ԫ���ź���������Ԫ���
//N��������Ԫ���ź���������Ԫ�ұ�
//��Ԫ�����λ�ò��� 
//���Ƿ�����λ�ò��䲻һ������Ԫ
//�����Ǵ�ǰ����ҵ���ǰλ����Ҫ������Ԫ�ص����ֵ�ſ��� 
//��������������λ�ò������ǵ�ǰ���е����ֵ 
int compare(const void* a,const void* b)
{
	if(*(int*)a>*(int*)b)//*a *bȡ��a,bָ���ֵ 
		return 1;
	else 
		return -1;
}

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	int a[n],c[n],d[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		c[i]=a[i];
	}
	qsort(c,n,sizeof(int),compare);//���� 
	int l=0,max=-1;
 	for(i=0;i<n;i++){
 		if(a[i]>max) max=a[i];//max��¼��ǰa�����ֵ 
 		if(a[i]==c[i]&&c[i]==max){//�ж��������� 
 			d[l++]=c[i];
		}	
	}
	qsort(d,l,sizeof(int),compare);
	printf("%d\n",l);
	for(i=0;i<l;i++){
		if(i==0) printf("%d",d[i]);
		else printf(" %d",d[i]);
	}
	printf("\n");//0����Ԫ û�ÿ��� ��ʽ���� 
	return 0;
} 
