#include<stdio.h>

int main()
{
	int a[1200];
	int b0[1000]={0},b1[1000]={0},b2[1000]={0},b3[1000]={0},b4[1000]={0};
	int n;
	scanf("%d",&n);
	int i;
	int p0=0,p1=0,p2=0,p3=0,p4=0;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		switch(a[i]%5){
			case 0: b0[p0++]=a[i];break;
			case 1: b1[p1++]=a[i];break;
			case 2: b2[p2++]=a[i];break;
			case 3: b3[p3++]=a[i];break;
			case 4: b4[p4++]=a[i];break;
		}	
	}
	
	int sum=0,flag=0;
	for(i=0;i<p0;i++){
		if(b0[i]%2==0){
			sum+=b0[i];
			flag=1;
		}
	}
	if(flag) printf("%d ",sum);
	else printf("N ");
	
	sum=0,flag=0;
	for(i=0;i<p1;i++){
		flag=1;
		if(i&1) sum-=b1[i];
		else sum+=b1[i];
	}
	if(flag) printf("%d ",sum);
	else printf("N ");
	
	if(p2) printf("%d ",p2);
	else printf("N ");
	
	sum=0,flag=0;
	for(i=0;i<p3;i++){
		flag=1;
		sum+=b3[i];
	}
	if(flag) printf("%0.1lf ",1.0*sum/p3);
	else printf("N ");
	
	flag=0;
	int max=-1;
	for(i=0;i<p4;i++){
		flag=1;
		if(b4[i]>max){
			max=b4[i];
		}
	}
	if(flag) printf("%d",max);
	else printf("N");
	
	return 0;
}
