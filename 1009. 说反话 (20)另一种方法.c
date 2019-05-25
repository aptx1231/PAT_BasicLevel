#include<stdio.h>
#include<string.h>

int main()
{
	char a[120];
	int b[120]={0};
	gets(a);
	int i,j;
	int la=strlen(a);
	for(i=0;i<la;i++){
		if(a[i]==' '){
			b[i]=1;//ур©у╦Я 
		}
	}
	b[la]=1;//из╠Ь 
	int tmp=la;
	for(i=la-1;i>=0;i--){
		if(b[i]==1){
			for(j=i+1;j<tmp;j++){
				printf("%c",a[j]);
			}
			tmp=i;
			printf(" ");
		}
	} 
	for(i=0;i<tmp;i++){
		printf("%c",a[i]);
	} 
	return 0;
}
