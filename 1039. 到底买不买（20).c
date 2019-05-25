#include<stdio.h>
#include<string.h>
int main()
{
	char a[1010];
	char b[1010];
	int c1[128]={0};
	int c2[128]={0};
	
	scanf("%s",a);
	scanf("%s",b);
	
	int i;
	for(i=0;a[i]!='\0';i++){
		c1[a[i]]++;
	}
	for(i=0;b[i]!='\0';i++){
		c2[b[i]]++;
	}
	
	int gap=0;
	for(i=0;i<128;i++){
		if(c2[i]>c1[i]){
			gap+=(c2[i]-c1[i]);
		}
	}
	if(!gap){
		printf("Yes %d",strlen(a)-strlen(b));
	}
	else{
		printf("No %d",gap);
	}
	return 0;
}
