#include<stdio.h>
#include<string.h>

int main()
{
	char a[1200];
	int b[10]={0};
	gets(a);
	int len=strlen(a);
	int i;
	for(i=0;i<len;i++){
		b[a[i]-'0']++;
	}
	for(i=0;i<10;i++){
		if(b[i])
			printf("%d:%d\n",i,b[i]);
	}
	return 0;
}
