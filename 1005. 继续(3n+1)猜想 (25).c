#include<stdio.h>
void Insert_Sort(int a[],int n)
{
	int p;
	for(p=1;p<n;p++){
		int tmp=a[p];/*取出未排序序列中的第一个元素*/
		int i;
		for(i=p;i>0&&a[i-1]>tmp;i--){
			a[i]=a[i-1];/*依次与已排序序列中元素比较并右移*/
		}
		a[i]=tmp;/*放进合适的位置 */
	}
} 

int main()
{
	int a[10000],b[10000]={0},c[10000];
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		int tmp=a[i];
		while(tmp!=1){
			if(tmp&1){
				tmp=3*tmp+1;
				tmp/=2;
				b[tmp]=1;
			}
			else{
				tmp/=2;
				b[tmp]=1;
			}	
		}
	}
	
	int p=0;
	for(i=0;i<n;i++){
		if(b[a[i]]==0){
			c[p++]=a[i];
		}
	}

	Insert_Sort(c,p);
	
	for(i=p-1;i>=0;i--){
		printf("%d",c[i]);
		if(i!=0){
			printf(" ");
		}
	}
	return 0;
} 
