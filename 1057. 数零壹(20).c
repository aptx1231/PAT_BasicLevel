#include<stdio.h>

int main()
{
	char a[100001];
	gets(a);

	int i;
	int sum=0;
	for(i=0;a[i]!='\0';i++){
		if(a[i]>='a'&&a[i]<='z'){
			sum+=(a[i]-'a'+1);
		}
		else if(a[i]>='A'&&a[i]<='Z'){
			sum+=(a[i]-'A'+1);
		}
	}
	
	int n1=0,n0=0;
	while(sum){
		if(sum&1) n1++;
		else n0++;
		sum/=2;
	}
	printf("%d %d",n0,n1);
	return 0;
 } 
