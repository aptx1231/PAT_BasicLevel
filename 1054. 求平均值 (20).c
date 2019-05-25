#include<stdio.h>
#include<stdlib.h>

int find(char s[])
{
	int i,j,cnt=0,flag=1;
	for(i=0;s[i]!='\0';i++){
		if(s[i]=='.') cnt++;//小数点个数==1 
		else if(s[i]<'0'||s[i]>'9') flag=0;//有没有不合法字符(除了0-9数字，负号在外边跳过) 
	}//小数点if-else跳过 
	if(cnt>1) flag=0;
	for(i=0;s[i]!='\0';i++){
		if(s[i]=='.') break;
	}
	cnt=0;
	for(j=i+1;s[j]!='\0';j++){//小数点后位数最大是2 
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
			if(find(s)==1||find(s+1)==1){//find(s+1)跳过了负号 
				f=atof(s);
				if(f>=-1000&&f<=1000){
					cnt++;
					sum+=f;
				}
				else{//每个if都有else 
					printf("ERROR: %s is not a legal number\n",s);
				}
			}
			else{//每个if都有else 
				printf("ERROR: %s is not a legal number\n",s);
			}
		}
		else{//每个if都有else 
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
