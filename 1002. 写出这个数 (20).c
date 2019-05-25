#include<stdio.h>
#include<string.h>

int main()
{
	char a[110];
	int b[10];
	scanf("%s",a);
	int i;
	int sum=0;
	for(i=0;i<strlen(a);i++){
		sum+=(a[i]-'0');
	}

	int tmp=sum;	
	int cnt=0;
	if(tmp){
		while(tmp>0){
			tmp/=10;
			cnt++;
		}
	}else cnt=1;
	
	int j=cnt;
	while(sum>0){
		b[--j]=sum%10;
		sum/=10;
	}
	for(i=0;i<cnt;i++){
		switch(b[i]){
			case 1:printf("yi");if(i!=cnt-1)printf(" "); break;
			case 2:printf("er");if(i!=cnt-1)printf(" "); break;
			case 3:printf("san");if(i!=cnt-1)printf(" "); break;
			case 4:printf("si");if(i!=cnt-1)printf(" "); break;
			case 5:printf("wu");if(i!=cnt-1)printf(" "); break;
			case 6:printf("liu");if(i!=cnt-1)printf(" "); break;
			case 7:printf("qi");if(i!=cnt-1)printf(" "); break;
			case 8:printf("ba");if(i!=cnt-1)printf(" "); break;
			case 9:printf("jiu");if(i!=cnt-1)printf(" "); break;
			case 0:printf("ling");if(i!=cnt-1)printf(" "); break;
		}
	}
	return 0;
}
