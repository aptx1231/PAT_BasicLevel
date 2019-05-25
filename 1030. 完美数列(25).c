#include<stdio.h>
#include<stdlib.h>

int a[100001];

int compare(const void* a,const void* b)
{
	return (*(const int*)a-*(const int*)b);//小到大 
}

int main()
{
  	long long n,p;
  	scanf("%ld %ld",&n,&p);
  	int i,j,max=1;
 	for(i=0;i<n;i++){
  	  	scanf("%d",&a[i]);
 	}
 	
  	qsort(a,n,sizeof(int),compare);
  	
  	for(j=0;j<n;j++){
    	long long tmp=a[j]*p;
    	for(i=j+max;i<n;i++){//跳跃max，保证i与j之间个数>max（等于max+1）加速！！！！			
     	 	if(a[i]<=tmp){//如果成立就是可以更新max， 
        		if((i-j+1)>max) max=i-j+1;
      		}
      		else{//不成立说明在此之前，就算前一位成立，最长也不会超过max个（最大是等于max)，没必要计算比较
	  			break;
	  		}
    	}
  	}
  	printf("%d",max);
  	
  	return 0;
}
