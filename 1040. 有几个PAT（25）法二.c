#include<stdio.h>
#include<string.h>
//�ѣ��� 
int main()
{
    //���� 
    char s[100009];
    gets(s);
    int len=strlen(s);
    int i,countp=0,countt=0,result=0;
    for(i=0;i<len;i++){
        if(s[i]=='T')
            countt++;//T������ 
    }
    for(i=0;i<len;i++){
        if(s[i]=='P') countp++;//��¼ǰ���м���P 
        if(s[i]=='T') countt--;//��¼����м���T �ܵ�T����ȥǰ�ߵ�T�� 
        if(s[i]=='A') result=(result+(countp*countt)%1000000007)%1000000007;
        //����Aʱ��ǰ�ߵ�P���Ժ�ߵ�T�������A��PAT���������е���Ӽ��� 
    }
    printf("%d",result); 
    return 0;
}
