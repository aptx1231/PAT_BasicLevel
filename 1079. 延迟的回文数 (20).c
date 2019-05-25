#include<stdio.h>
#include<string.h>

int judge(int a[],int len)
{
    int i,j;
    for(i=0,j=len-1;i<j;i++,j--){
        if(a[i]!=a[j])
            return 0;
    }
    return 1;
}

int main()
{
    char a[1009];
    int b[1009];//原顺序
    int c[1009];//反序
    int ans[1009]={0};//不超过1000位 但是加和可以超过1000位！！！
    gets(a);
    int i,j;
    for(i=0;a[i]!='\0';i++){
        ans[i]=a[strlen(a)-i-1]-'0';
    }
    i--;//如果直接就是回文数 打印i--为了和后边的打印保持一致 i是ans最高位
    int len=strlen(a),cnt=0;
    while(1){
        if(judge(ans,len)==1||cnt>=10) break;//先判断 直接就是回文数就输出就得了
        for(i=0;i<len;i++){
            b[i]=ans[len-i-1];
        }
        for(i=0;i<len;i++){
            c[i]=ans[i];
        }
        for(i=0;i<=len;i++){
            ans[i]=0;
        }
        for(i=len-1;i>=0;i--){
            printf("%d",c[i]);
        }
        printf(" + ");
        for(i=len-1;i>=0;i--){
            printf("%d",b[i]);
        }
        printf(" = ");
        for(j=0;j<len;j++){
            ans[j]+=(b[j]+c[j]);
            if(ans[j]>=10){
                ans[j+1]+=ans[j]/10;
                ans[j]%=10;
            }
        }
        //打印ans
        for(i=j;i>=0;i--){
            if(ans[i]) break;//i是ans最高位
        }
        if(i<0){
            len=1;
            printf("0");
        }
        else {
            for(j=i;j>=0;j--){
                printf("%d",ans[j]);
            }
            len=i+1;
        }
        cnt++;
        printf("\n");
    }
    if(cnt<10){
        if(i<0){
            printf("0");
        }
        else {
            for(j=i;j>=0;j--){
                printf("%d",ans[j]);
            }
        }
        printf(" is a palindromic number.\n");
    }
    else{
        printf("Not found in 10 iterations.\n");
    }
    return 0;
}
