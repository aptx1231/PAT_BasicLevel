#include<stdio.h>
#include<string.h>

int main()
{
	int n;
	char a[11000],l[11000],r[11000],mid[11000],l0[11000];
	scanf("%d",&n);
	getchar(); 
	while(n--){
		gets(a);
		int i,j,k,m,p,q,numP=0,numT=0;
		int flag=1;
		for(i=0;i<strlen(a);i++){
			if(a[i]=='P') numP++;
			if(a[i]=='T') numT++; 
			if(a[i]!='P'&&a[i]!='A'&&a[i]!='T'){//û�б����ĸ 
				flag=0;
			}	
		}
		if(numP!=1||numT!=1){//PT����ֻ��һ�� 
			flag=0;
		}
		if(flag){
			int i=j=k=m=0;
				while(a[i]!='P'){
					l[j++]=a[i++];
				}
				if(a[i]=='P'){
					i++;
				}
				while(a[i]!='T'){
					mid[k++]=a[i++];
				}
				if(a[i]=='T'){
					i++;
				}
				while(a[i]!='\0'){
					r[m++]=a[i++];
				}
			l[j]='\0';
			mid[k]='\0';
			r[m]='\0';
			for(p=0;p<strlen(l);p++){
				if(l[p]!='A'){
					flag=0;
				}
			}
			for(p=0;p<strlen(mid);p++){
				if(mid[p]!='A'){
					flag=0;
				}
			}
			for(p=0;p<strlen(r);p++){
				if(r[p]!='A'){
					flag=0;
				}
			}

			strcpy(l0,l);
			if(strlen(mid)>=1){//�м��м���A���Ҳ�������ļ�������ο���������� 
				for(q=0;q<strlen(mid)-1;q++){
					strcat(l0,l);
				} 
				if(strcmp(l0,r)!=0){
					flag=0;
				}
			}
			else flag=0;
			//if(strlen(mid)==0) flag=0;
			//if(strlen(mid)*strlen(l)!=strlen(r)){
			//	flag=0;
			//}	
		}
		
		if(flag){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}
