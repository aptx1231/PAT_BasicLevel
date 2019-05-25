#include<stdio.h>

struct stu{
	char num[100];
	int jishi;
	int kaoshi;
}a[1001]; 

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++){
		scanf("%s %d %d",a[i].num,&a[i].jishi,&a[i].kaoshi);
	}
	int m,tmp;
	scanf("%d",&m);
	while(m--){
		scanf("%d",&tmp);
		for(i=0;i<n;i++){
			if(a[i].jishi==tmp){
				printf("%s %d\n",a[i].num,a[i].kaoshi);
				break;
			}
		}
	}
	return 0;
}
