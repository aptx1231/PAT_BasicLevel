#include<stdio.h>
#include<string.h>

struct per{
	char name[8];
	int year;
	int month;
	int day;
}a[100005];

int compare(const void *a,const void *b)
{
	int k;
	if(((const struct per*)a)->year>((const struct per*)b)->year){
		k=1;
	}
	else if(((const struct per*)a)->year<((const struct per*)b)->year){
		k=-1;
	}
	else{
		if(((const struct per*)a)->month>((const struct per*)b)->month){
			k=1;
		}
		else if(((const struct per*)a)->month<((const struct per*)b)->month){
			k=-1;
		}
		else{
			if(((const struct per*)a)->day>((const struct per*)b)->day){
				k=1;
			}
			else if(((const struct per*)a)->day<((const struct per*)b)->day){
				k=-1;
			}
		}
	}
	return k;
} 

int main()
{
	int n;
	int y,m,d;
	int i=0,cnt=0,flag;
	char name[8];
	scanf("%d",&n);
	while(n--){
		scanf("%s %d/%d/%d",name,&y,&m,&d);
		flag=0;
		if(y>1814&&y<2014){
			cnt++;
			flag=1;
		} 
		else if(y==1814){
			if(m>9){
				cnt++;
				flag=1;
			}
			else if(m==9){
				if(d>=6){
					cnt++;
					flag=1;
				} 
			}	
		}
		else if(y==2014){
			if(m<9){
				cnt++;
				flag=1;
			}
			else if(m==9){
				if(d<=6){
					cnt++;
					flag=1;
				} 
			}
		}
		if(flag==1){
			a[i].year=y;
			a[i].month=m;
			a[i].day=d;
			strcpy(a[i].name,name);
			i++;
		}	
	}
	if(cnt==0){
		printf("0");
		return 0;
	}
	else{
		qsort(a,cnt,sizeof(struct per),compare);
		printf("%d %s %s",cnt,a[0].name,a[cnt-1].name);
	}
	return 0;
}
