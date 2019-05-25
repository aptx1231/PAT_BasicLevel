#include<stdio.h>
#include<stdlib.h>

int b[101];

void print(int a[],int n);
void Merge(int a[],int tmpA[],int L,int R,int RightEnd);
void Merge_pass(int a[],int tmpA[],int n,int len); 
void Merge_Sort(int a[],int n);
int compare(int a[],int n);
void IsInsert(int a[],int n,int i);

void Merge_pass(int a[],int tmpA[],int n,int len)
{
	int i;
	for(i=0;i<=n-2*len;i+=2*len){
		Merge(a,tmpA,i,i+len,i+2*len-1);
	}
	if(i+len<n){
		Merge(a,tmpA,i,i+len,n-1);
	}
	else{
		int j;
		for(j=i;j<n;j++){
			tmpA[j]=a[j];
		}
	}
}

void Merge_Sort(int a[],int n)//稳定 
{
	int len;
	int* tmpA;
	printf("Merge Sort\n");
	len=1;
	tmpA=(int*)malloc(n*sizeof(int));
	while(len<n){//a,tmpA互为存储排序结果的新数组，不用开很多个新数组 
		Merge_pass(a,tmpA,n,len);//a排序存到tmpA 
		if(compare(tmpA,n)==1){
			Merge_pass(tmpA,a,n,len*2);//再调用一步---len*2 
			print(a,n);
		}
		len*=2;
		
		Merge_pass(tmpA,a,n,len);//更换步长，tmpaA排序后存到a里 
		if(compare(a,n)==1){
			Merge_pass(a,tmpA,n,2*len);
			print(tmpA,n);
		}
		len*=2;
	} 
	free(tmpA);
}

/* L = 左边起始位置, R = 右边起始位置, RightEnd = 右边终点位置*/ 
void Merge(int a[],int tmpA[],int L,int R,int RightEnd)
{
	/* 将有序的A[L]~A[R-1]和A[R]~A[RightEnd]归并成一个有序序列 */
	int LeftEnd=R-1;/* 左边终点位置 */
	int tmp=L;/* 有序序列的起始位置 */
	
	while(L<=LeftEnd&&R<=RightEnd){
		if(a[L]<a[R]){
			tmpA[tmp++]=a[L++];/* 将左边元素复制到TmpA */
		}
		else{
			tmpA[tmp++]=a[R++];/* 将右边元素复制到TmpA */
		}	
	} 
	
	while(L<=LeftEnd){
		tmpA[tmp++]=a[L++];/* 直接复制左边剩下的 */
	}
	while(R<=RightEnd){
		tmpA[tmp++]=a[R++];/* 直接复制右边剩下的 */
	}
} 

void print(int a[],int n)
{
	int i;
	for(i=0;i<n;i++){
		printf("%d",a[i]);
		if(i!=n-1){
			printf(" ");
		}
	}
	printf("\n");
}

int compare(int a[],int n)
{
	int flag=1;
	int i;
	for(i=0;i<n;i++){
		if(a[i]!=b[i]){
			flag=0;
			break;
		}
	}
	return flag;
}

void PerInsert(int a[],int n,int i)//插入排序的一步 
{
	int j;
	int tmp=a[i];
	for(j=i;j>=1&&a[j-1]>tmp;j--){
		a[j]=a[j-1];
	}
	a[j]=tmp;
}

int Insert_Sort(int a[],int n)
{
	int i;
	int isprint=0;
	for(i=1;i<n;i++){
		PerInsert(a,n,i);
		if(compare(a,n)==1){
			printf("Insertion Sort\n");
			isprint=1;
			if(i==n-1) i--;//如果调用到最后一次 还要调用一次的话 先减回去 
			PerInsert(a,n,i+1);
			print(a,n);
			break;
		}
	}
	return isprint;
}

int main()
{
	int n;
	scanf("%d",&n);
	int a[n],c[n];
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		c[i]=a[i];
	}
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	
	int isprint=0;
	isprint=Insert_Sort(a,n); 
	if(isprint==0){
		Merge_Sort(c,n);
	}
	return 0;
}
