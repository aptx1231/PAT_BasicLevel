#include<stdio.h>

struct per{
	int num;
	int x;
	int y;
}a[10009];

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	int max=-1,min=20000;
	int l,r1,r2;
	for(i=0;i<n;i++){
		scanf("%d %d %d",&a[i].num,&a[i].x,&a[i].y);
		l=a[i].x*a[i].x+a[i].y*a[i].y;
		if(l>max){
			max=l;
			r1=i;
		}
		if(l<min){
			min=l;
			r2=i;
		}
	}
	printf("%04d %04d",a[r2].num,a[r1].num);
	return 0;
}
