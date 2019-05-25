#include<stdio.h>

int main()
{
	char a[10001];
	gets(a);
	int num[128]={0};
	int i,max=-1;
	for(i=0;a[i]!='\0';i++){
		if(a[i]=='P'||a[i]=='A'||a[i]=='T'||a[i]=='e'||a[i]=='s'||a[i]=='t')
			num[a[i]]++;
		if(max<num[a[i]])
			max=num[a[i]];
	}
	while(max--){
		if(num['P']){
			printf("P");
			num['P']--;
		}	
		if(num['A']){
			printf("A");
			num['A']--;
		}	
		if(num['T']){
			printf("T");
			num['T']--;
		}
		if(num['e']){
			printf("e");
			num['e']--;
		}
		if(num['s']){
			printf("s");
			num['s']--;
		}
		if(num['t']){
			printf("t");
			num['t']--;
		}	
	}
	return 0;
}
