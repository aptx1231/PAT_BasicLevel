#include<stdio.h>
#include<string.h>

int num[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char cmp[]={'1','0','X','9','8','7','6','5','4','3','2'};

int main()
{
	char a[20];
	int n,i,cnt=0;
	scanf("%d",&n);
	while(n--){
		scanf("%s",a);
		int flag=1;
		int sum=0,end;
		for(i=0;i<17;i++){
			if(a[i]<'0'||a[i]>'9'){
				flag=0;
			}
		}
		if(flag){
			for(i=0;i<17;i++){
				sum+=(a[i]-'0')*num[i]; 
			}
			end=sum%11;
			if(cmp[end]!=a[17]){
				flag=0;
			}
		}
		if(flag==0){
			printf("%s\n",a);
			cnt++;
		}	
	}
	if(cnt==0){
		printf("All passed\n");
	}
	return 0;
} 
