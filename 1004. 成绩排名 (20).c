#include<stdio.h>

struct student{
	char name[20];
	char num[20];
	int score;
}a[1000];

int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	int i,max=-1,min=101;
	for(i=0;i<n;i++){
		scanf("%s %s %d",a[i].name,a[i].num,&a[i].score);
		getchar();
		if(a[i].score>max) 
			max=a[i].score;
		if(a[i].score<min)
			min=a[i].score;
	}
	for(i=0;i<n;i++){
		if(a[i].score==max) 
			printf("%s %s\n",a[i].name,a[i].num);
	}
	for(i=0;i<n;i++){
		if(a[i].score==min) 
			printf("%s %s\n",a[i].name,a[i].num);
	}
	return 0;
}
