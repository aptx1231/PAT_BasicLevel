#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char a[100000];
	char b[100000];//n==40�ر��λ ����һЩ 
	scanf("%s",a);
	int n;
	scanf("%d",&n);
	int i,cnt=1,l=0;
	n--;//�������һ�� 
	while(n--){
		l=0;//b��ȫ�µ����� 
		for(i=0;a[i]!='\0';i++){
			cnt=1;//Ĭ��һ�� �������Ķ���һ�� 
			while(a[i]==a[i+1]){//���������ظ� 
				cnt++;
				i++;//�ҵ���ȵľ������i++ 
			}
			b[l++]=a[i];
			b[l++]=cnt+'0';//cnt������ ת�� 
		}
		b[l]='\0';
		strcpy(a,b);//����  
	}
	puts(a);
	return 0;
}
