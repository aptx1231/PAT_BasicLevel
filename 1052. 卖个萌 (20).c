#include<stdio.h>

char a1[11][30];
char a2[11][30];
char a3[11][30];

int get(char a[][30])
{
	char c,ch;
	int i=-1,j=0;
	c=getchar();
	while(c!='['){
		c=getchar();
	}
	while(c=='['){
		i++;
		j=0;
		ch=getchar();
		while(ch!=']'){
			a[i][j++]=ch;
			ch=getchar();
		}	
		a[i][j]='\0';
		c=getchar();
		if(c=='\n') return i+1;
		while(c!='['){
			c=getchar();
			if(c=='\n') return i+1;
		}
	}
	return i+1;
}

/* 
int  get(char p[][30])
{
    int i=-1,j=0,c;
    int flag=0;//是否进入[]的标志位
    while((c=getchar())!='\n'){
        if(c=='['){       
            flag =1;//已经进入“[”
            i++;//保存下一个符号
            j=0;
        }
        else if(c==']'){
            flag = 0;//已经退出“]”
            p[i][j]=0;'\0'
        }       
        else{
        	if(flag ==1)
            	p[i][j++]=c;//将[]内的字符保存进数组
        }
    }   
    return i+1;
}
*/
int main()
{
	//int i;
	int l1=get(a1);
	//for(i=0;i<l1;i++) printf("*%s*\n",a1[i]);
	int l2=get(a2);
	//for(i=0;i<l2;i++) printf("*%s*\n",a2[i]);
	int l3=get(a3);
	//for(i=0;i<l3;i++) printf("*%s*\n",a3[i]);
		
	int n;
	scanf("%d",&n);
	int q,w,e,r,t;
	while(n--){
		scanf("%d %d %d %d %d",&q,&w,&e,&r,&t);
		q--;w--;e--;r--;t--;
		if(q<0||w<0||e<0||r<0||t<0){	
			printf("Are you kidding me? @\\/@\n");
		}
		else if(q>=l1||t>=l1||w>=l2||r>=l2||e>=l3){
			printf("Are you kidding me? @\\/@\n");
		}
		else{
			printf("%s(%s%s%s)%s\n",a1[q],a2[w],a3[e],a2[r],a1[t]);
		}
	}
	return 0;
}
