#include<stdio.h>
#include<string.h>
int main()
{
    int key[178]={0};//���滵��-----key[i]==1���ǲ������ 
    int i,check=0;//check�˶��Ƿ������
    char ch;
    while((ch=getchar())!='\n')
    {
        if(ch>='A'&&ch<='Z'){
        	key[ch-'A'+'a']=1;//��Сд��ĸ--СдҲҪɾ�� 
		}
        key[ch]=1;//���������붼������� 
    }
    if(key['+']){
    	for(i='A';i<='Z';i++)
			key[i]=1;//�ϵ��������������д�д�޷����
	}
	
    while((ch=getchar())!='\n')
    {
        if(key[ch]==0)
        	printf("%c",ch);
        check=1;
    }
    if(check==0)
		printf("\n");//���û������������\n
	return 0; 
}
