#include<stdio.h>
#include<stdlib.h>

int find(char s[])
{
	int i,j,cnt=0,flag=1;
	for(i=0;s[i]!='\0';i++){
		if(s[i]=='.') cnt++;//С�������==1 
		else if(s[i]<'0'||s[i]>'9') flag=0;//��û�в��Ϸ��ַ�(����0-9���֣��������������) 
	}//С����if-else���� 
	if(cnt>1) flag=0;
	for(i=0;s[i]!='\0';i++){
		if(s[i]=='.') break;
	}
	cnt=0;
	for(j=i+1;s[j]!='\0';j++){//С�����λ�������2 
		if(s[j]>='0'&&s[j]<='9'){
			cnt++;
		}
	}
	if(cnt>=3) flag=0;
	return flag;
}

int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	int i;
	int cnt=0;
	double f,sum=0;
	char s[100];
	for(i=0;i<n;i++){
		scanf("%s",s);
		getchar();
		if((s[0]>='0'&&s[0]<='9')||(s[0]=='-'&&s[1]>='0'&&s[1]<='9')){
			if(find(s)==1||find(s+1)==1){//find(s+1)�����˸��� 
				f=atof(s);
				if(f>=-1000&&f<=1000){
					cnt++;
					sum+=f;
				}
				else{//ÿ��if����else 
					printf("ERROR: %s is not a legal number\n",s);
				}
			}
			else{//ÿ��if����else 
				printf("ERROR: %s is not a legal number\n",s);
			}
		}
		else{//ÿ��if����else 
			printf("ERROR: %s is not a legal number\n",s);
		}
	}
	
	if(cnt==0){
		printf("The average of 0 numbers is Undefined\n");
	}
	else if(cnt==1){
		printf("The average of 1 number is %0.2lf\n",sum);
	}
	else{
		printf("The average of %d numbers is %0.2lf\n",cnt,sum/cnt);
	}
	return 0;
} 
