#include<stdio.h>

int gcd(int m,int n)
{
	int r;
	while(n>0){
		r=m%n;
		m=n;
		n=r;
	}
	if(m==1)
		return 1;
	else
		return 0;
}

int main()
{
	int a1,a2,b1,b2,m;
	scanf("%d/%d",&a1,&b1);
	scanf("%d/%d",&a2,&b2);
	scanf("%d",&m);
	if(a1*b2>a2*b1){
		int t;
		t=a1;
		a1=a2;
		a2=t;
		t=b1;
		b1=b2;
		b2=t;
	}
	double c1,c2;
	c1=1.0*a1/b1;
	c2=1.0*a2/b2;
	//没规定c1<c2！！！！ 
	if(c2<c1){
		double tmp=c1;
		c1=c2;
		c2=tmp;
	}
	//printf("%f %f",c1,c2);
	int i;
	int flag=0;
	for(i=1;i<m;i++){
		if(gcd(i,m)==1){
			double c=1.0*i/m;
			//if(c>c1&&c<c2){
			if(m*a1<b1*i&&b2*i<a2*m){//转除法为乘法 避免浮点数比较大小 
				if(flag==0){
					printf("%d/%d",i,m);
				}	
				else{
					printf(" %d/%d",i,m);
				}
				flag=1;
			}
		}
	}
	return 0;
} 
