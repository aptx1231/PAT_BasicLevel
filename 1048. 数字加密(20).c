#include<stdio.h>
#include<string.h>

int main()
{
	char a[101];
	char b[101];
	char a0[101];
	char b0[101];
	char c[101];
	
	scanf("%s",a0);
	scanf("%s",b0);
	
	int la=strlen(a0);
	int lb=strlen(b0);
	int i;
	for(i=0;i<la;i++){
		a[la-1-i]=a0[i];
	}
	a[la]='\0';
	for(i=0;i<lb;i++){
		b[lb-1-i]=b0[i];
	}
	b[lb]='\0';
	
	int max;
	if(la>=lb){
		max=la;
		for(i=lb;i<max;i++){
			b[i]='0';
		}
		b[max]='\0';
	}
	else{
		max=lb;
		for(i=la;i<max;i++){
			a[i]='0';
		}
		a[max]='\0';
	}
	
	for(i=0;i<max;i++){
		if(i%2==0){
			int tmp=(a[i]-'0'+b[i]-'0')%13;
			if(tmp<10){
				c[i]=(char)(tmp+'0');
			}
			else{
				if(tmp==10) c[i]='J';
				else if(tmp==11) c[i]='Q';
				else if(tmp==12) c[i]='K';
 			}
		}
		else{
			int tmp=(int)(b[i]-a[i]);
			if(tmp<0){
				tmp+=10;
				c[i]=(char)(tmp+'0');
			}
			else{
				c[i]=(char)(tmp+'0');
			}
		}
	}
	
	for(i=max-1;i>=0;i--){
		printf("%c",c[i]);
	}
	return 0;
} 
