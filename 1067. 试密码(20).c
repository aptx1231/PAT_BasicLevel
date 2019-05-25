#include<stdio.h>
#include<string.h>

int main()
{
	int n;
	char a[200];
	char b[200];
	scanf("%s",a);
	scanf("%d",&n);
	getchar();
	int i;
	for(i=0;i<n;i++){
		gets(b);
		if(strlen(b)==1&&b[0]=='#'){
			break;
		}
		if(strcmp(a,b)==0){
			printf("Welcome in");
			break;
		}
		else{
			printf("Wrong password: %s\n",b);
			if(i==n-1){
				printf("Account locked");
				break;
			}
		}	
	}
	
	return 0;
} 
