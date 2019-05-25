#include<stdio.h>
#include<string.h>

char a[10000];
char b[10000];
char c[10000];
int is[100];

int main()
{
	scanf("%s",a);
	scanf("%s",b);
	int i,j;
	int la=strlen(a),lb=strlen(b);
	for(i=0;i<la;i++){
		if(a[i]>='a'&&a[i]<='z'){
			a[i]-=32;
		}
	}
	for(i=0;i<lb;i++){
		if(b[i]>='a'&&b[i]<='z'){
			b[i]-=32;
		}
	}

	int flag=1,p=0;
	for(i=0;i<la;i++){
		flag=1;
		for(j=0;j<lb;j++){
			if(a[i]==b[j]){
				flag=0;
			}	
		}
		if(flag){
			c[p++]=a[i];
		}
	}
	for(i=0;i<p;i++){
		if(is[c[i]]==0){
			printf("%c",c[i]);
			is[c[i]]=1;
		}
	}
	return 0;
} 
