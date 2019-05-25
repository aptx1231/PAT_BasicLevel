#include<stdio.h>
#include<string.h> 

struct ques{
	int score;
	int num;
	int right;
	char ans[6];
}a[101];

int main()
{
	int n,m;
	int i,j,p=0,t;
	char b[6];
	int max=-1;
	int cnt[101]={0};
	int sum[1001]={0};
	
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d %d %d",&a[i].score,&a[i].num,&a[i].right);
		for(j=0;j<a[i].right;j++){
			getchar();
			a[i].ans[j]=getchar();
		}
		a[i].ans[j]='\0';
	} 
	
	for(j=0;j<n;j++){
		sum[j]=0;
		for(i=0;i<m;i++){
			p=0;
			getchar();
			getchar();
			scanf("%d",&t);
			while(t--){
				getchar();
				b[p++]=getchar();
			}
			b[p]='\0';
			getchar();
			
			if(strcmp(a[i].ans,b)==0){
				sum[j]+=a[i].score;
			}
			else cnt[i]++;
			
			if(cnt[i]>max)
				max=cnt[i];
		}
	}
	for(i=0;i<n;i++){
		printf("%d\n",sum[i]);
	}
	if(max){
		printf("%d",max);
		for(i=0;i<m;i++){
			if(cnt[i]==max){
				printf(" %d",i+1);
			}
		}
	}
	else{
		printf("Too simple\n");
	}
	return 0;
}
