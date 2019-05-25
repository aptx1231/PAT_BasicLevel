#include<stdio.h>
//³ıkÈ¡Óà·¨ 
int main()
{
	int a,b,c,n,p=0,tmp,i;
	scanf("%d %d %d",&a,&b,&n);
	c=a+b;
	if(c==0){
		printf("0");
		return 0;
	} 
	int ans[100];
	while(c>0){
		tmp=c/n;
		ans[p++]=c-tmp*n;
		c=tmp;
	}
	for(i=p-1;i>=0;i--){
		printf("%d",ans[i]);
	}
	return 0;
}
