#include<stdio.h>
#include<stdlib.h>
//左小右大是主元
//主元和排好序的序列位置是相同的
//前提是主元的话 
//M个小于主元的排好序仍在主元左边
//N个大于主元的排好序仍在主元右边
//主元排序后位置不变 
//但是反过来位置不变不一定是主元
//必须是从前向后找到当前位置需要是所有元素的最大值才可以 
//所以两个条件：位置不变且是当前序列的最大值 
int compare(const void* a,const void* b)
{
	if(*(int*)a>*(int*)b)//*a *b取出a,b指向的值 
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
	qsort(c,n,sizeof(int),compare);//排序 
	int l=0,max=-1;
 	for(i=0;i<n;i++){
 		if(a[i]>max) max=a[i];//max记录当前a的最大值 
 		if(a[i]==c[i]&&c[i]==max){//判断两个条件 
 			d[l++]=c[i];
		}	
	}
	qsort(d,l,sizeof(int),compare);
	printf("%d\n",l);
	for(i=0;i<l;i++){
		if(i==0) printf("%d",d[i]);
		else printf(" %d",d[i]);
	}
	printf("\n");//0个主元 没用空行 格式错误 
	return 0;
} 
