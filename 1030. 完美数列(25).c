#include<stdio.h>
#include<stdlib.h>

int a[100001];

int compare(const void* a,const void* b)
{
	return (*(const int*)a-*(const int*)b);//С���� 
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
    	for(i=j+max;i<n;i++){//��Ծmax����֤i��j֮�����>max������max+1�����٣�������			
     	 	if(a[i]<=tmp){//����������ǿ��Ը���max�� 
        		if((i-j+1)>max) max=i-j+1;
      		}
      		else{//������˵���ڴ�֮ǰ������ǰһλ�������Ҳ���ᳬ��max��������ǵ���max)��û��Ҫ����Ƚ�
	  			break;
	  		}
    	}
  	}
  	printf("%d",max);
  	
  	return 0;
}
