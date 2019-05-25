#include<stdio.h>

int main()
{
	char c[1001];
	int num[128]={0};
	gets(c);
	int i;
	int max=-1;
	for(i=0;c[i]!='\0';i++){
		if(c[i]>='A'&&c[i]<='Z'){
			c[i]+=32;
		}
		if(c[i]>='a'&&c[i]<='z'){
			num[c[i]]++;
		}
		if(num[c[i]]>max){
			max=num[c[i]];
		}
	}
	for(i='a';i<='z';i++){
		if(num[i]==max){
			printf("%c %d",i,max);
			return 0;
		}
	}
}
