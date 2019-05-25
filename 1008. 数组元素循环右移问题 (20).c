#include<stdio.h>

void move(int a[],int n)
{
	int i;
	int tmp;
	tmp=a[n-1];
	for(i=n-2;i>=0;i--){
		a[i+1]=a[i];
	}
	a[0]=tmp;
}

void Swap(int* a,int* b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}

void swap_3(int a[],int n,int m)
{
	int i,j;
	for(i=0,j=n-1;i<j;i++,j--){
		Swap(&a[i],&a[j]);
	}
	for(i=0,j=m-1;i<j;i++,j--){
		Swap(&a[i],&a[j]);
	}
	for(i=m,j=n-1;i<j;i++,j--){
		Swap(&a[i],&a[j]);
	}
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n];
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	if(m>n) m%=n;
	/*while(m--){
		move(a,n);
	}*/
	swap_3(a,n,m);
	for(i=0;i<n;i++){
		printf("%d",a[i]);
		if(i!=n-1){
			printf(" ");
		}
	}
	return 0;
}
