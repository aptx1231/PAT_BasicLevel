#include<stdio.h>

int a[100001];
int c[100001];
int mark[100001];
int out[100001];

void Insert_Sort(int a[],int n)
{
	int i,j,tmp;
	for(i=1;i<n;i++){
		tmp=a[i];
		for(j=i;j>0&&a[j-1]>tmp;j--){
			a[j]=a[j-1];
		}
		a[j]=tmp;
	}
}

int main()
{	
	int i,j;
	for(i=0;i<100000;i++){//��Ϊ0Ҳ�������������� 
		a[i]=-1;
	}
	int n,m;
	scanf("%d",&m);
	while(m--){
		scanf("%d %d",&i,&j);
		a[i]=j;
		a[j]=i;
	}
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&c[i]);
		mark[c[i]]=1;
	}
	int p=0;
	for(i=0;i<n;i++){
		if(a[c[i]]==-1){//û��ż 
			out[p++]=c[i];
		}
		else{
			if(mark[a[c[i]]]==0){//����żû�� 
				out[p++]=c[i];
			}
		}
	}
	Insert_Sort(out,p);
	printf("%d\n",p);
	for(i=0;i<p;i++){
		printf("%05d",out[i]);//��0ռλ 5λ��� 
		if(i!=p-1){
			printf(" ");
		}
	}
	return 0;
}
