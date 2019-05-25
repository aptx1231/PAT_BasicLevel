#include <stdio.h>
#include <stdlib.h>

int a[100000+1];

int comp(const void*a,const void*b){//�Ӵ�С���� 
    return *(int*)b-*(int*)a;
}

int main(){//nlogn�㷨
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
        scanf("%d",&a[i]);
        
    qsort(&a[1],n,sizeof(int),comp); 
    
    for(i=1;i<=n;i++)
        if(a[i]<=i) break;
    printf("%d",i-1);
    return 0;
}
//i    1  2 3 4 5 6 7 8 9 10  ���� 
//a[i] 10 9 8 8 7 7 6 6 3 2  ·�� 
//�Ӵ�С����
//10>1  ˵����1�������1�� 
//9>2  ˵����2�������2�� ��Ϊǰ�ߵ�10>9>2
//8>3 ˵����3�������3��.... 
//.....����󣡣�E ��E���ﳵ����EӢ������ֵ
//7>6˵����6�������6�� 
//6<=7�� ˵����7��Ĳ���7���ǲ������ģ������Ȼ��8��Ĳ����ܳ���8����...break;
//���i-1 
 
 
//O(N^2)���� 
/*int main()
{
	int n;
	scanf("%d",&n);
	int i,j,t;
	int a[100000]={0};
	for(i=0;i<n;i++){
		scanf("%d",&t);
		for(j=0;j<t;j++){
			if(j>n) break;
			a[j]++;
		}
	}
	for(i=n;i>=0;i--){
		if(a[i]>=i){
			printf("%d",i);
			return 0;
		}
	}
}*/ 
