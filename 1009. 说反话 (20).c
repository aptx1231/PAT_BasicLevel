#include<stdio.h>
#include<string.h>

int main()
{
	char a[100];
	char s[120][100];
	int i=0,j,p=0;
	char c;

	while(1){
		c=getchar();
		if(c=='\n') break;
		if(c!=' '){
			s[i][p++]=c;
		}
		else{
			s[i][p]='\0';
			i++;
			p=0;
		}
	}
	for(j=i;j>=0;j--){
		printf("%s",s[j]);
		if(j!=0){
			printf(" ");
		}
	}
	return 0;
}
