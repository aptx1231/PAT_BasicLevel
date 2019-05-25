#include<stdio.h>
#include<math.h>
int main()
{
	int n1,n2,s;
	scanf("%d %d",&n1,&n2);
	double sum=(n2-n1)/100.0;
	if(fabs(sum-(int)(sum))>=0.5){
		s=(int)(sum)+1;
	}
	else{
		s=(int)(sum);
	}
	//printf("%d",s);
	int h,min,sec;
	h=s/3600;
	min=(s-(h*3600))/60;
	sec=s%60;
	printf("%02d:%02d:%02d",h,min,sec);
	return 0;
} 
