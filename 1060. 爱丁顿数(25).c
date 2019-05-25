#include <stdio.h>
#include <stdlib.h>

int a[100000+1];

int comp(const void*a,const void*b){//从大到小排序 
    return *(int*)b-*(int*)a;
}

int main(){//nlogn算法
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
//i    1  2 3 4 5 6 7 8 9 10  天数 
//a[i] 10 9 8 8 7 7 6 6 3 2  路程 
//从大到小排序
//10>1  说明比1大的至少1天 
//9>2  说明比2大的至少2天 因为前边的10>9>2
//8>3 说明比3大的至少3天.... 
//.....找最大！！E 有E天骑车超过E英里的最大值
//7>6说明比6大的至少6天 
//6<=7了 说明比7大的不到7个是不成立的，后边自然比8大的不可能超过8个了...break;
//输出i-1 
 
 
//O(N^2)慢！ 
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
