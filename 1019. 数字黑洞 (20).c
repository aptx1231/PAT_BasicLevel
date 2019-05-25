#include<stdio.h>

void Insert_Sort(int a[])
{
	int i,j;
	for(i=1;i<4;i++){
		int tmp=a[i];
		for(j=i;j>0&&a[j-1]>tmp;j--){
			a[j]=a[j-1];
		}
		a[j]=tmp;
	}
}

int max(int a[])
{
	return a[3]*1000+a[2]*100+a[1]*10+a[0]; 
}

int min(int a[])
{
	return a[0]*1000+a[1]*100+a[2]*10+a[3]; 
}

void oper(int a[],int n)
{
	a[0]=n%10;
	a[1]=n/10%10;
	a[2]=n/100%10;
	a[3]=n/1000;
}

int main()
{
	int n;
	scanf("%d",&n);
	int a[4];
	oper(a,n);
	if(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3]){
		printf("%d - %d = 0000\n",n,n);
		return 0;
	}
	Insert_Sort(a);
	
	int t=max(a)-min(a);
	while(t!=6174){
		printf("%d - %04d = %04d\n",max(a),min(a),t);
		oper(a,t);
		Insert_Sort(a);
		t=max(a)-min(a);
	}
	printf("%d - %04d = %04d\n",max(a),min(a),t);
	return 0;
}
