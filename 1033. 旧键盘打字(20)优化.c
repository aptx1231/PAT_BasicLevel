#include<stdio.h>
#include<string.h>
int main()
{
    int key[178]={0};//储存坏键-----key[i]==1就是不会输出 
    int i,check=0;//check核对是否有输出
    char ch;
    while((ch=getchar())!='\n')
    {
        if(ch>='A'&&ch<='Z'){
        	key[ch-'A'+'a']=1;//存小写字母--小写也要删除 
		}
        key[ch]=1;//存所有输入都不会输出 
    }
    if(key['+']){
    	for(i='A';i<='Z';i++)
			key[i]=1;//上档键坏掉，则所有大写无法打出
	}
	
    while((ch=getchar())!='\n')
    {
        if(key[ch]==0)
        	printf("%c",ch);
        check=1;
    }
    if(check==0)
		printf("\n");//如果没有输出，则输出\n
	return 0; 
}
