#include<stdio.h>

struct node{
	double price;
	double amount;
	double per;
}a[1001];

int compare(const void *a,const void *b)
{
	int k;
	if(((const struct node*)a)->per>((const struct node*)b)->per){
		k=-1;
	}
	else if(((const struct node*)a)->per<((const struct node*)b)->per){
		k=1;
	}
	return k;
}

int main()
{
	int n,max;
	scanf("%d %d",&n,&max);//�۸��������������С�������� 
	int i,j;
	for(i=0;i<n;i++){
		scanf("%lf",&a[i].amount);
	} 
	for(i=0;i<n;i++){
		scanf("%lf",&a[i].price);
		a[i].per=a[i].price/a[i].amount;
	} 
	qsort(a,n,sizeof(struct node),compare);

	double sum=0;
	for(i=0;i<n;i++){
		sum+=a[i].amount;
		if(sum>=max) break;//���ܲ��� һֱû��break i==n a[i]���������0 
	}
	sum-=a[i].amount;
	double all=0;
	for(j=0;j<i;j++){
		all+=a[j].price;
	}
	if(sum+a[i].amount==max){//û��break if else���仰������ִ�� ������� �۸���Ȼ������� 
    	all+=a[i].price;
  	}
  	else if(sum+a[i].amount>max){
    	double gap=max-sum;
    	all+=(gap/a[i].amount*a[i].price);//������if else if�ж� ����a[i]=0����Ϊ0���� 
  	}
	printf("%0.2lf",all);
	return 0;
} 
