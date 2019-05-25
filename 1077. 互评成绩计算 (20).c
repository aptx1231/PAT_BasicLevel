#include<stdio.h>

int main()
{
	int n,k;
	int i,j;
	int teach,t,max,min;
	double ave=0.0;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%d",&teach);
		int sum=0,cnt=0;
		max=-1;
		min=101;
		for(j=0;j<n-1;j++){
			scanf("%d",&t);
			if(t>=0&&t<=k){
				sum+=t;
				cnt++;
				if(t>max) max=t;
				if(t<min) min=t;
			}
		}
		sum-=max;
		sum-=min;
		ave=1.0*sum/(cnt-2);
		ave=(ave+teach)/2.0;
		if(ave-(int)ave>=0.5){
			printf("%d\n",(int)ave+1);
		}
		else{
			printf("%d\n",(int)ave);
		}
	}
	return 0;
}
