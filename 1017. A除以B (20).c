#include<stdio.h>
#include<string.h>

int main()
{
	char c[1200];
	int b;
	int a[1200],ans[1200];
	scanf("%s %d",c,&b);
	int i,l=0,r;
	int len=strlen(c);
	for(i=0;i<len;i++){
		a[i]=c[i]-'0';
	}
	
	if(len==1){
		int t=a[0]/b;
		printf("%d %d",t,a[0]%b);
		return 0;
	}
	if(a[0]<b){
		i=1;
		a[i]=a[0]*10+a[1];
	}
	else i=0; 

	for(;i<len;i++){
		ans[l++]=a[i]/b;
		if(i!=len-1){
			a[i+1]=10*(a[i]%b)+a[i+1];
		}
		else{
			r=a[i]%b;
		}
	}
	for(i=0;i<l;i++){
		printf("%d",ans[i]);
	}
	printf(" %d",r);
	return 0;
}
