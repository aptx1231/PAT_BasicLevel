#include<stdio.h>

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int i,j;
	int t;
	int score[m],ans[m],sum[101]={0}; 
	for(i=0;i<m;i++){
		scanf("%d",&score[i]);
	}
	for(i=0;i<m;i++){
		scanf("%d",&ans[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&t);
			if(t==ans[j]){
				sum[i]+=score[j];
			}
		}
	}
	for(i=0;i<n;i++){
		printf("%d\n",sum[i]);
	}
	return 0;
}
