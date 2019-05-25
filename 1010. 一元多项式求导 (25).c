#include<stdio.h>

int main()
{
	int a[10000],b[10000];
	char c;
	int i=0;
	int cnt=0;
	while(1){
		scanf("%d %d",&a[i],&b[i]);
		if(a[i]*b[i]) cnt++;
		i++;
		c=getchar();
		if(c=='\n') break;
	}
	//printf("%d\n",cnt);
	if(cnt==0){
		printf("0 0");
	}
	for(i=0;i<cnt;i++){
		if(a[i]*b[i]){
			printf("%d %d",a[i]*b[i],b[i]-1);
		}
		if(i!=cnt-1){
			printf(" ");
		}
	}
	return 0;
}
