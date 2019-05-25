#include<stdio.h>
#include<string.h>

int check(char a[])
{
	int i;
	for(i=0;a[i]!='\0';i++){
		if((a[i]>='0'&&a[i]<='9')||(a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z')||a[i]=='.'){
			;
		}
		else{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int n;
	char a[85];
	int num=0,str=0;
	scanf("%d",&n);
	getchar();
	while(n--){
		gets(a);
		str=num=0;
		if(strlen(a)<6){
			printf("Your password is tai duan le.\n");
		}
		else if(check(a)==0){
			printf("Your password is tai luan le.\n");
		}
		else{
			int i;
			for(i=0;a[i]!='\0';i++){
				if((a[i]>='0'&&a[i]<='9')){
					num=1;
				}
			}
			for(i=0;a[i]!='\0';i++){
				if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z')){
					str=1;
				}
			}
			if(num==0&&str==1){
				printf("Your password needs shu zi.\n");
			}
			if(num==1&&str==0){
				printf("Your password needs zi mu.\n");
			}
			if(num==1&&str==1){
				printf("Your password is wan mei.\n");
			}
		}
	}
	return 0;
} 
