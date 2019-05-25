#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* s[]={"tret", 
"jan", "feb", "mar", "apr", "may", "jun", 
"jly", "aug", "sep", "oct", "nov", "dec", 
"tam", "hel", "maa", "huh", "tou", "kes",
"hei", "elo", "syy", "lok", "mer", "jou",
};
int main()
{
	int n,t,i,j;
	char a[30];
	int num;
	int num1,num2;
	scanf("%d",&n);
	getchar();
	while(n--){
		gets(a);
		if(a[0]>='0'&&a[0]<='9'){
			num=(int)atof(a);
			if(num){
				num1=num%13;//个位 
				num/=13;
				num2=num%13;//十位
				if(num2) printf("%s",s[num2+12]);
				if(num2!=0&&num1==0) printf("\n");
				if(num2&&num1) printf(" ");
				if(num1) printf("%s\n",s[num1]);
			}
			else{
				printf("%s\n",s[0]);
			}
		}
		else{
			if(strlen(a)==3){
				char tmp[3];
				for(i=0;i<3;i++){
					tmp[i]=a[i];
				}
				tmp[i]='\0';
				for(i=0;i<=24;i++){
					if(strcmp(tmp,s[i])==0){
						if(i<=12){
							printf("%d\n",i);
						}
						else{
							printf("%d\n",13*(i-12));
						}
					}
				}
			}
			else if(strlen(a)==4){
				printf("0\n");
			}	
			else if(strlen(a)==7){
				char tmp[3];
				for(i=0;i<3;i++){
					tmp[i]=a[i];
				}
				tmp[i]='\0';
				for(i=13;i<=24;i++){
					if(strcmp(tmp,s[i])==0){
						break;
					}
				}
				i-=12;
				num=i*13;
				for(i=4;i<7;i++){
					tmp[i-4]=a[i];
				}
				tmp[i-4]='\0';
				for(i=1;i<=12;i++){
					if(strcmp(tmp,s[i])==0){
						break;
					}
				}
				num+=i;
				printf("%d\n",num);
			}
		}
	}
	return 0;
}
