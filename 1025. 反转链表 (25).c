#include<stdio.h>

struct node{
	int Data;
	int Next;
}a[100005];

int main()
{
  	int p,num,k;
  	int address,data,next,flag,i;
  	scanf("%d %d %d",&p,&num,&k);
  	while(num--){
  	  scanf("%d %d %d",&address,&data,&next);
  	  a[address].Data=data;
  	  a[address].Next=next;
  	}
  	
  	int t=p;
  	num=0;
  	for(i=0;t!=-1;i++){  
    	num++;
    	t=a[t].Next;
  	}  
  	int maxn=num/k;
  	if(maxn*k==num) flag=1;
  	else flag=0;
  
  	int tmp,_new,_old,new_p,tmp_begin,tmp_end=p;
  	int cnt=1;
  	int n0=0;
  	while(n0<maxn){
    	cnt=1;
    	_new=p;
    	_old=a[p].Next;
    	while(cnt<k){
     		cnt++;
    		tmp=a[_old].Next;
    	  	a[_old].Next=_new;
    	  	_new=_old;
    	  	_old=tmp;
    	}
    	a[p].Next=_old;
    	tmp_begin=_new;    
    	if(n0!=0){
    	  	a[tmp_end].Next=tmp_begin;
    	 	tmp_end=p;
    	}
    	else new_p=tmp_begin;
    	n0++;
    	p=_old;
  	}
  		
  	if(flag==1) a[tmp_end].Next=-1;
  	t=new_p;
  	for(i=0;t!=-1;i++){  
   	 	if(a[t].Next!=-1)
    		printf("%05d %d %05d\n",t,a[t].Data,a[t].Next);
    	else 
      		printf("%05d %d -1\n",t,a[t].Data);
    	t=a[t].Next;
  	}  
  	return 0;
}
