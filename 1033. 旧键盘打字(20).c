#include<stdio.h>
#include<string.h>

int main()
{
	char a[200];
	char b[100009];
	gets(a); //可能没有坏的按键----scanf不会读入这个空行，用gets 
	gets(b);
	
	int la;
	la=strlen(a);
	int i,j,p=0;
	int flag=0;
	for(i=0;i<la;i++){
		if(a[i]=='+'){
			flag=1;
		}
		if(a[i]>='A'&&a[i]<='Z'){
			a[i]+=32;
		}
	}

	if(flag){
		for(i=0;b[i]!='\0';i++){
			if(b[i]<'A'||b[i]>'Z'){
				b[p++]=b[i];
			}
		}
		b[p]='\0';
		for(i=0,p=0;a[i]!='\0';i++){
			for(j=0;b[j]!='\0';j++){
				if(a[i]!=b[j]){
					b[p++]=b[j];
				}
			}
			b[p]='\0';
			p=0;
		}
	}
	else{
		for(i=0;a[i]!='\0';i++){
			if(a[i]>='a'&&a[i]<='z'){
				a[la++]=a[i]-32;
			}
		}
		a[la]='\0';
		for(i=0,p=0;a[i]!='\0';i++){
			for(j=0;b[j]!='\0';j++){
				if(a[i]!=b[j]){
					b[p++]=b[j];
				}
			}
			b[p]='\0';
			p=0;
		}
	}
	if(b[0]!='\0')
		puts(b);
	else
		printf("\n");	
	return 0;
} 
