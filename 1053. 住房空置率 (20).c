#include<stdio.h>

int main()
{
	int n;
	double e;
	int D;
	int n1=0,n2=0,j;
	scanf("%d %lf %d",&n,&e,&D);
	for(j=0;j<n;j++){
		int m;
		scanf("%d",&m);
		double a[m];
		int i;
		int cnt=0;
		int flag=0;
		for(i=0;i<m;i++){
			scanf("%lf",&a[i]);
			if(a[i]<e){
				cnt++;
			}
		}
		if(cnt>m*0.5){
			flag=1;
			if(m>D){
				flag=2;
			}
		}
		if(flag==1) n1++;
		if(flag==2) n2++;
	}
	printf("%0.1lf%% %0.1lf%%\n",100.0*n1/n,100.0*n2/n);
	return 0;
} 
