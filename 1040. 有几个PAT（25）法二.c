#include<stdio.h>
#include<string.h>
//难！！ 
int main()
{
    //法二 
    char s[100009];
    gets(s);
    int len=strlen(s);
    int i,countp=0,countt=0,result=0;
    for(i=0;i<len;i++){
        if(s[i]=='T')
            countt++;//T的总数 
    }
    for(i=0;i<len;i++){
        if(s[i]=='P') countp++;//记录前边有几个P 
        if(s[i]=='T') countt--;//记录后边有几个T 总的T数减去前边的T数 
        if(s[i]=='A') result=(result+(countp*countt)%1000000007)%1000000007;
        //遇到A时，前边的P乘以后边的T就是这个A的PAT个数，所有的相加即可 
    }
    printf("%d",result); 
    return 0;
}
